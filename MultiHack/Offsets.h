#pragma once

#include <Windows.h>

const DWORD playerBase = 0x00A9947C;
const DWORD entityBase = 0x04A3BA44;
const DWORD crosshairOffset = 0x00008CF4;
const DWORD teamOffset = 0x000000F0;
const DWORD healthOffset = 0x000000FC;
const DWORD EntLoopDist = 0x10;
const DWORD m_fFlags = 0x00000100;
const DWORD attack = 0x02EAD958;
const DWORD jump = 0x04AD0248;
const DWORD spotted = 0x935;
const DWORD isDormant = 0x000000e9;
const DWORD glowObjectBase = 0x04B527B4;
const DWORD glowIndex = 0x000086B0;

extern DWORD ClientDLL;
extern DWORD LocalPlayer;