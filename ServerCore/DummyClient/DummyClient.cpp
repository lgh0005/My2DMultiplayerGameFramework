#include "pch.h"

int main()
{
	// I. Ŭ���̾�Ʈ ���� ���� �����
	WSADATA wsaData;
	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 1;

	SOCKET clientSocket = ::socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket == INVALID_SOCKET)
		return 1;
	
	// II. ������ ������ IP �ּ�(������ ������), ��Ʈ ��ȣ ����
	SOCKADDR_IN serverAddr;
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	::inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
	serverAddr.sin_port = ::htons(7777);

	if (::connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
		return 1;

	cout << "Connected To Server!" << endl;

	// III. ���
	while (true)
	{
		// TODO
	}

	::closesocket(clientSocket);
	::WSACleanup();
}