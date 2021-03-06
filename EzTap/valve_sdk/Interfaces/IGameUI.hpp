#pragma once
#include "../../VirtualFunction.hpp"

class IGameUI
{
public:
	VF(void, createCmdMsgBox, 20, (const char* title, const char* message, bool showOk = true, bool showCancel = false, const char* okCommand = nullptr, const char* cancelCommand = nullptr, const char* closedCommand = nullptr, const char* legend = nullptr, const char* unknown = nullptr), (this, title, message, showOk, showCancel, okCommand, cancelCommand, closedCommand, legend, unknown));
};