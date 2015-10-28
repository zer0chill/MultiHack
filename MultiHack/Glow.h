#pragma once

#include "Offsets.h"
#include "ProcMem.h"

class Glow
{
public:
	Glow();
	~Glow();
	void Run();
private:
	int MyTeam;
	int EnemyTeam;
	int crosshairID;
	DWORD EnemyInCH;
};