#pragma once
#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>
#include <Psapi.h>
#pragma comment(lib, "psapi.lib")
#include "Console.hpp"

#define INRANGE(x,a,b)    (x >= a && x <= b) 
#define getBits( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define getByte( x )    (getBits(x[0]) << 4 | getBits(x[1]))


namespace Memory
{
	static unsigned long FindPattern(DWORD moduleBase, std::string pattern)
	{
		const char* pat = pattern.c_str();
		unsigned long firstMatch = 0;
		MODULEINFO miModInfo; GetModuleInformation(GetCurrentProcess(), (HMODULE)moduleBase, &miModInfo, sizeof(MODULEINFO));
		unsigned long rangeEnd = moduleBase + miModInfo.SizeOfImage;
		for (unsigned long pCur = moduleBase; pCur < rangeEnd; pCur++)
		{
			if (!*pat)
				return firstMatch;

			if (*(PBYTE)pat == '\?' || *(BYTE*)pCur == getByte(pat))
			{
				if (!firstMatch)
					firstMatch = pCur;

				if (!pat[2])
					return firstMatch;

				if (*(PWORD)pat == '\?\?' || *(PBYTE)pat != '\?')
					pat += 3;

				else
					pat += 2;
			}
			else
			{
				pat = pattern.c_str();
				firstMatch = 0;
			}
		}
		return NULL;
	}

	static void ReadPointer(std::string module, std::string sig, DWORD& output, int offset = 0x0, int extra = 0, bool removeModule = false)
	{
		unsigned long moduleBase = reinterpret_cast<unsigned long>(GetModuleHandleA(module.c_str()));

		if (!moduleBase)
		{
			console.Error("Failed to locate module \"%s\"!\n", module.c_str());
			return;
		}

		unsigned long sigResult = Memory::FindPattern(moduleBase, sig.c_str()) + offset;

		if (!sigResult)
		{
			console.Error("Failed to find signature \"%s\"!\n", sig.c_str());
			return;
		}

		sigResult = *reinterpret_cast<unsigned long*>(sigResult);
		sigResult += extra;

		if (removeModule)
			sigResult -= moduleBase;

		output = sigResult;
	}

	inline uintptr_t traceToExit;
}