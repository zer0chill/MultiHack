#pragma once

#include "Offsets.h"
#include "ProcMem.h"

class Trigger
{
public:
	Trigger();
	~Trigger();
	void Shoot();

private:
	int MyTeam;
	int crosshairID;
	int EnemyHealth;
	int EnemyTeam;
};