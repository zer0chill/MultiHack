#include "Bhop.h"

Bhop::Bhop()
{
}

Bhop::~Bhop()
{
}

void Bhop::Jump()
{
	int onGround = mem.Read<int>(LocalPlayer + m_fFlags) & 1;
	if (onGround)
	{
		mem.Write(ClientDLL + jump, 5);
		Sleep(1);
	}
	else
	{
		mem.Write(ClientDLL + jump, 4);
		Sleep(1);
	}
}