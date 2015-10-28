#include "Auth.h"

#define SIGINT 2
#define SIGKILL 9
#define SIGQUIT 3

Auth::Auth()
{
}

Auth::~Auth()
{
}

bool Auth::Login(string username, string password)
{
	buf = "L";
	buf += username;
	buf += ";";
	buf += password;
	Sleep(5);

	Connect("107.6.140.56", 27015);
	res = send(sock, buf.c_str(), sizeof(buf), 0);

	if (res == 0)
	{
		//0==other side terminated conn
		printf("\nSERVER terminated connection\n");
		Sleep(40);
		closesocket(client);
		client = 0;
	}
	else if (res == SOCKET_ERROR)
	{
		//-1 == send error
		printf("Socket error\n");
		Sleep(40);
	}

	char RecvdData[100] = "";
	string recData;
	int ret;

	ret = recv(sock, RecvdData, sizeof(RecvdData), 0);

	recData += RecvdData[0];
	recData += RecvdData[1];

	cout << recData << endl;

	if (recData == "OK")
	{
		loggedIn = true;
		closesocket(client);
		WSACleanup();
		return true;
	}

	closesocket(client);
	WSACleanup();
	Sleep(100);
	return false;
}

int Auth::Connect(string ip, int port)
{
	sockaddr_in ser;
	sockaddr addr;

	ser.sin_family = AF_INET;
	ser.sin_port = htons(port);                    //Set the port
	ser.sin_addr.s_addr = inet_addr(ip.c_str());      //Set the address we want to connect to

	memcpy(&addr, &ser, sizeof(SOCKADDR_IN));

	res = WSAStartup(MAKEWORD(1, 1), &data);      //Start Winsock

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);       //Create the socket

	res = connect(sock, &addr, sizeof(addr));               //Connect to the server
	memcpy(&ser, &addr, sizeof(SOCKADDR));
	return 0;
}