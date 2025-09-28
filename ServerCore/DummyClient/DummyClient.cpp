#include "pch.h"

int main()
{
	// I. 클라이언트 전용 소켓 만들기
	WSADATA wsaData;
	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 1;

	SOCKET clientSocket = ::socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket == INVALID_SOCKET)
		return 1;

	// I-1. 소켓 논블로킹화
	u_long on = 1;
	if (::ioctlsocket(clientSocket, FIONBIO, &on) == SOCKET_ERROR)
		return 1;
	
	// II. 연결할 서버의 IP 주소(지금은 루프백), 포트 번호 설정
	SOCKADDR_IN serverAddr;
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	::inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
	serverAddr.sin_port = ::htons(7777);

	while (true)
	{
		if (::connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
		{
			if (::WSAGetLastError() == WSAEWOULDBLOCK)
				continue;

			// 이건 이미 연결이 되었는데 또 연결을 요청할 경우에 대한 처리.
			if (::WSAGetLastError() == WSAEISCONN)
				break;
		}
	}

	cout << "Connected To Server!" << endl;

	// III. 통신
	while (true)
	{
		// TODO
		// 논블로킹 소켓인 경우, send/recv 모두 논블로킹으로 진행되므로 WSAEWOULDBLOCK 체크.
	}

	::closesocket(clientSocket);
	::WSACleanup();
}