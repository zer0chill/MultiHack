#pragma once

#include <Windows.h>
#include <thread>
#include <iostream>

#include "Offsets.h"
#include "ProcMem.h"
#include "Trigger.h"
#include "Bhop.h"
#include "Radar.h"
#include "Glow.h"
#include "SHA512.h"

class Engine
{
public:
	Engine();
	~Engine();
	void Run();

private:
	Trigger trigger;
	Bhop bhop;
	Radar radar;
	Glow glow;

	bool isRunning;
	bool gON;
	bool rON;
};