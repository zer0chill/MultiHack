#include "Glow.h"

Glow::Glow()
{
}

Glow::~Glow()
{
}

void Glow::Run()
{
	MyTeam = mem.Read<int>(LocalPlayer + teamOffset);

	DWORD glow_GlowPointer = mem.Read<DWORD>(ClientDLL + glowObjectBase);
	for (int i = 0; i < 64; i++)
	{
		int glow_currentPlayer = mem.Read<int>(ClientDLL + entityBase + ((i - 1) * 16));
		bool glow_currentPlayerDormant = mem.Read<bool>(glow_currentPlayer + isDormant);
		int glow_currentPlayerGlowIndex = mem.Read<int>(glow_currentPlayer + glowIndex);
		EnemyTeam = mem.Read<int>(glow_currentPlayer + teamOffset);

		if (glow_currentPlayerDormant == 1)
		{
			continue;
		}
		else
		{
			if (MyTeam == EnemyTeam)
			{
				mem.Write<float>((glow_GlowPointer + ((glow_currentPlayerGlowIndex * 0x34) + 0x4)), 0.f);
				mem.Write<float>((glow_GlowPointer + ((glow_currentPlayerGlowIndex * 0x34) + 0x8)), 0.f);
				mem.Write<float>((glow_GlowPointer + ((glow_currentPlayerGlowIndex * 0x34) + 0xC)), 1.f);
				mem.Write<float>((glow_GlowPointer + ((glow_currentPlayerGlowIndex * 0x34) + 0x10)), 1.f);
				mem.Write<BOOL>((glow_GlowPointer + ((glow_currentPlayerGlowIndex * 0x34) + 0x24)), true);
				mem.Write<BOOL>((glow_GlowPointer + ((glow_currentPlayerGlowIndex * 0x34) + 0x25)), false);
			}
			else
			{
				mem.Write<float>((glow_GlowPointer + ((glow_currentPlayerGlowIndex * 0x34) + 0x4)), 1.f);
				mem.Write<float>((glow_GlowPointer + ((glow_currentPlayerGlowIndex * 0x34) + 0x8)), 0.f);
				mem.Write<float>((glow_GlowPointer + ((glow_currentPlayerGlowIndex * 0x34) + 0xC)), 0.f);
				mem.Write<float>((glow_GlowPointer + ((glow_currentPlayerGlowIndex * 0x34) + 0x10)), 1.f);
				mem.Write<BOOL>((glow_GlowPointer + ((glow_currentPlayerGlowIndex * 0x34) + 0x24)), true);
				mem.Write<BOOL>((glow_GlowPointer + ((glow_currentPlayerGlowIndex * 0x34) + 0x25)), false);
			}
		}
	}
}