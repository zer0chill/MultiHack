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