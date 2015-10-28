#include "Trigger.h"

Trigger::Trigger()
{

}

Trigger::~Trigger()
{

}

void Trigger::Shoot()
{
	MyTeam = mem.Read<int>(LocalPlayer + teamOffset);
	crosshairID = mem.Read<int>(LocalPlayer + crosshairOffset);
	DWORD EnemyInCH = mem.Read<DWORD>(ClientDLL + entityBase + ((crosshairID - 1) * EntLoopDist));
	EnemyHealth = mem.Read<int>(EnemyInCH + healthOffset); // Enemy in crosshair's
	EnemyTeam = mem.Read<int>(EnemyInCH + teamOffset); // Enemy in crosshair's team
	if (MyTeam != EnemyTeam && EnemyHealth > 0)
	{
		Sleep(10);
		mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, 0, 0);
		//mem.Write(ClientDLL + attack, 5);
		//Sleep(5);
		//mem.Write(ClientDLL + attack, 4);
		//Sleep(4);
	}
}