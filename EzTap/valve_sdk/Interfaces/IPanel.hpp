#pragma once
#include "../../VirtualFunction.hpp"

class IPanel
{
public:
	VF(const char*, get_panel_name, 36, (unsigned int panel_id), (this, panel_id));
};