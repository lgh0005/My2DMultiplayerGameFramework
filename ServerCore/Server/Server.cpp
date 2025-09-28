#include "pch.h"

int main()
{
	// I. ���� ����(socket)
	WSADATA wsaData;

	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 1;

	SOCKET listenSocket = ::socket(AF_INET, SOCK_STREAM, 0);
	if (listenSocket == INVALID_SOCKET)
		return 1;

	// I-1. ���� ����ŷȭ �� REUSEADDR �ɼ� Ȱ��ȭ
	u_long on = 1;
	if (::ioctlsocket(listenSocket, FIONBIO, &on) == SOCKET_ERROR)
		return 1;

	BOOL bOption = TRUE;
	if (::setsockopt(listenSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&bOption, sizeof(BOOL)) == SOCKET_ERROR)
		return 1;

	// II. �ּ�/��Ʈ ��ȣ ����(bind)
	SOCKADDR_IN serverAddr;
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = ::htonl(INADDR_ANY);
	serverAddr.sin_port = ::htons(7777);

	if (::bind(listenSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
		return 1;

	// III. ���� ����(listen)
	if (::listen(listenSocket, SOMAXCONN) == SOCKET_ERROR)
		return 1;

	// IV. �մ� �ޱ�(accept)
	while (true)
	{
		SOCKADDR_IN clientAddr;
		::memset(&clientAddr, 0, sizeof(clientAddr));
		int addrLen = sizeof(clientAddr);

		SOCKET clientSocket = ::accept(listenSocket, (SOCKADDR*)&clientAddr, &addrLen);
		if (clientSocket == INVALID_SOCKET)
		{
			// IV-1. ����ŷ�� ���ؼ� WSAEWOULDBLOCK�� ��� ���� Ŭ�� ���� �ʾ����Ƿ� continue
			if (::WSAGetLastError() == WSAEWOULDBLOCK)
				continue;
		}

		// V. Ŭ��� ���
		// ex) Ŭ���̾�Ʈ�� IP �ּ� ���
		// ����ŷ ������ ���, send/recv ��� ����ŷ���� ����ǹǷ� WSAEWOULDBLOCK üũ.
		char ip[16];
		::inet_ntop(AF_INET, &clientAddr.sin_addr, ip, sizeof(ip));
		cout << "Client Connected! IP = " << ip << endl;
	}

	::closesocket(listenSocket);
	::WSACleanup();
}