#pragma once
#include "../Classes/Vector.hpp"
#include "../../VirtualFunction.hpp"

class IVDebugOverlay
{
public:
	VF(bool, ScreenPosition, 13, (const Vector& point, Vector& screen), (this, point, screen));
};