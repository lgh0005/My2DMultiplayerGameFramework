#include "pch.h"

int main()
{
	// I. 소켓 생성(socket)
	WSADATA wsaData;

	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 1;

	SOCKET listenSocket = ::socket(AF_INET, SOCK_STREAM, 0);
	if (listenSocket == INVALID_SOCKET)
		return 1;

	// II. 주소/포트 번호 설정(bind)
	SOCKADDR_IN serverAddr;
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = ::htonl(INADDR_ANY);
	serverAddr.sin_port = ::htons(7777);

	if (::bind(listenSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
		return 1;

	// III. 업무 개시(listen)
	if (::listen(listenSocket, SOMAXCONN) == SOCKET_ERROR)
		return 1;

	// IV. 손님 받기(accept)
	while (true)
	{
		SOCKADDR_IN clientAddr;
		::memset(&clientAddr, 0, sizeof(clientAddr));
		int addrLen = sizeof(clientAddr);

		SOCKET clientSocket = ::accept(listenSocket, (SOCKADDR*)&clientAddr, &addrLen);
		if (clientSocket == INVALID_SOCKET)
			return 1;

		// V. 클라와 통신
		// ex) 클라이언트의 IP 주소 출력
		char ip[16];
		::inet_ntop(AF_INET, &clientAddr.sin_addr, ip, sizeof(ip));
		cout << "Client Connected! IP = " << ip << endl;
	}

	::closesocket(listenSocket);
	::WSACleanup();
}