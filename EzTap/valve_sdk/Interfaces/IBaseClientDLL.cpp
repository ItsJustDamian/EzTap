#include "IBaseClientDLL.hpp"

void CHudChat::ChatPrintf(int iPlayerIndex, int iFilter, const char* fmt, ...)
{
    char msg[1024];

    va_list args;
    va_start(args, fmt);
    vsprintf(msg, fmt, args);
    //CallVFunction<void(__cdecl*)(void*, int, int, const char*, ...)>(this, 26)(this, iPlayerIndex, iFilter, fmt);
    //VFNC::oldCallVFunc<void(__cdecl*)(void*, int, int, const char*, ...)>(this, 26)(this, iPlayerIndex, iFilter, fmt);
    va_end(args);
}
