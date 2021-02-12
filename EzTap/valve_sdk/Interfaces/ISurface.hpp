#pragma once
#include "../../Interfaces.hpp"
#include "../../VirtualFunction.hpp"

class ISurface
{
public:
	VF(void, unlockCursor, 66, (), (this));
	VF(unsigned long, font_create, 71, (), (this));
	VF(void, set_font_glyph, 72, (unsigned long font, const char* windowsFontName, int tall, int weight, int blur, int scanlines, int flags), (this, font, windowsFontName, tall, weight, blur, scanlines, flags));
};