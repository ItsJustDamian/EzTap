#include "Utils.hpp"

void Utils::SetClantag(const char* tag)
{
	if (!interfaces.Engine->isIngame() || !LocalPlayer)
		return;

	static auto fnChangeClantag = reinterpret_cast<int(__fastcall*)(const char*, const char*)>(Memory::FindPattern(reinterpret_cast<DWORD>(GetModuleHandleA("engine.dll")), "53 56 57 8B DA 8B F9 FF 15"));
	fnChangeClantag(tag, tag);
}

typedef void (*IsReadyCallbackFn) (void);

void Utils::SetPlayerReady()
{
	static auto SetLocalPlayerReadyFn = reinterpret_cast<bool(__stdcall*)(const char*)>(Memory::FindPattern(reinterpret_cast<DWORD>(GetModuleHandleA("client.dll")), "55 8B EC 83 E4 F8 8B 4D 08 BA ? ? ? ? E8 ? ? ? ? 85 C0 75 12"));
	if (SetLocalPlayerReadyFn)
		SetLocalPlayerReadyFn("");
}
