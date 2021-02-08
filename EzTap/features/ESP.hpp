#pragma once
#include "../Hooks.hpp"
#include "../Interfaces.hpp"

namespace ESP
{
	void BoxEsp(int index, C_BaseEntity* pEntity, bool nameEsp = true, bool healthEsp = true, bool armorEsp = true);
	void DrawMisc(C_BaseEntity* pEntity, ClientClass* pEntityClientClass);
	void Render();
}