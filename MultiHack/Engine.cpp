#include "Engine.h"

using namespace std;

DWORD ClientDLL;
DWORD LocalPlayer;

Engine::Engine()
{
	mem.Process("csgo.exe");
	ClientDLL = mem.Module("client.dll");
	LocalPlayer = mem.Read<DWORD>(ClientDLL + playerBase);

	isRunning = true;
	rON = true;
	gON = true;
}

Engine::~Engine()
{
	
}

void Engine::Run()
{
	/* string username, password;
	string hashedPass;
	auth.loggedIn = false;
	while (!auth.loggedIn)
	{
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		hashedPass = sha512(password);

		if (!auth.Login(username, password))
		{
			cout << "Invalid username/password" << endl;
		}
	} */

	system("cls");
	cout << "Numpad 1 to toggle radar" << endl;
	cout << "Numpad 2 to toggle glow" << endl;
	cout << "Glow: " << gON << endl;
	cout << "Radar: " << rON << endl;

	/* TCHAR url[] = TEXT("http://www.puu.sh/kKcnL/adda3fe309.mp3");

	HRESULT res = URLDownloadToFile(NULL, url, "adda3fe309.mp3", 0, NULL);

	if (res == S_OK) 
	{
		printf("Ok\n");
	}
	else if (res == E_OUTOFMEMORY) 
	{
		printf("Buffer length invalid, or insufficient memory\n");
	}
	else if (res == INET_E_DOWNLOAD_FAILURE) 
	{
		printf("URL is invalid\n");
	}
	else {
		printf("Other error: %d\n", res);
	}

	string Pcommand = "play adda3fe309.mp3";
	mciSendString(Pcommand.c_str(), NULL, 0, 0);

	MessageBox(NULL, "Hi, I am an Albanian virus but because of poor technology in my country unfortunately I am not able to harm your computer. Please be so kind to delete one of your important files yourself and then foward me to other users. Many thanks for your cooperation! Best regards,Albanian virus", "Virus Alert !", MB_YESNOCANCEL);
	*/

	while (isRunning)
	{
		if (GetAsyncKeyState(VK_MBUTTON))
		{
			trigger.Shoot();
		}

		if (GetAsyncKeyState(VK_SPACE))
		{
			bhop.Jump();
		}

		if (GetAsyncKeyState(VK_NUMPAD1))
		{
			rON = !rON;
			system("cls");
			cout << "Numpad 1 to toggle radar" << endl;
			cout << "Numpad 2 to toggle glow" << endl;
			cout << "Glow: " << gON << endl;
			cout << "Radar: " << rON << endl;
			Sleep(100);
		}

		if (GetAsyncKeyState(VK_NUMPAD2))
		{
			gON = !gON;
			system("cls");
			cout << "Numpad 1 to toggle radar" << endl;
			cout << "Numpad 2 to toggle glow" << endl;
			cout << "Glow: " << gON << endl;
			cout << "Radar: " << rON << endl;
			Sleep(100);
		}

		if (rON)
		{
			radar.DoShit();
		}

		if (gON)
		{
			glow.Run();
		}
	}
}