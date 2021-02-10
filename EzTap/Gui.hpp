#pragma once
#include "Hooks.hpp"
#include <lmcons.h>
#include <filesystem>
#include <string>
#include <iostream>
#include "IconFont.hpp"
#include "features/events/KillChat.hpp"
#include "lua/LuaEngine.hpp"

namespace Gui
{
	void Render();
	void Watermark();

	void RenderTab1();
	void RenderTab2();
	void RenderTab3();
	void RenderTab4();
	void RenderTab5();
	void RenderTab6();
	void RenderTab7();
};