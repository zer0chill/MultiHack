#pragma once

#include <windows.h>
#include <winsock.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <signal.h>
#include <stdlib.h>
#include <string>

#pragma comment (lib, "Ws2_32.lib")

using namespace std;

class Auth
{
public:
	Auth();
	~Auth();
	bool Login(string username, string password);
	int Connect(string ip, int port);

	bool loggedIn;

private:
	SOCKET sock, client;
	DWORD poll;
	int res, i = 1, port = 999;
	string buf;
	char msg[100];
	char ip[15];
	WSADATA data;
};