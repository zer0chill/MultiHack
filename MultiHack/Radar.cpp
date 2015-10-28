#include "Radar.h"

Radar::Radar()
{
}


Radar::~Radar()
{
}

void Radar::DoShit()
{
	for (int i = 0; i < 32; i++)
	{
		DWORD ep = ClientDLL + entityBase + ((i - 1) * 0x10);
		int ep2 = mem.Read<int>(ep);
		mem.Write<int>(ep2 + spotted, 1);
	}
}