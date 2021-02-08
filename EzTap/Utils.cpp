#include "Utils.hpp"

void Utils::SetClantag(const char* tag)
{
	if (!interfaces.Engine->isIngame() || !LocalPlayer)
		return;

	static auto fnChangeClantag = reinterpret_cast<int(__fastcall*)(const char*, const char*)>(Memory::FindPattern(reinterpret_cast<DWORD>(GetModuleHandleA("engine.dll")), "53 56 57 8B DA 8B F9 FF 15"));
	fnChangeClantag(tag, tag);
}
