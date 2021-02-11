#include "Gui.hpp"

int iTab;
void color()
{
	ImGuiStyle& style = ImGui::GetStyle();
	style.Colors[ImGuiCol_Text] = ImVec4(0.86f, 0.93f, 0.89f, 0.78f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.86f, 0.93f, 0.89f, 0.78f);
	style.Colors[ImGuiCol_WindowBg] = ImColor(15, 15, 15, 255);
	style.Colors[ImGuiCol_Border] = ImColor(15, 15, 15, 255);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.09f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.04f, 0.04f, 0.04f, 0.88f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.20f, 0.22f, 0.27f, 0.75f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.35f, 0.35f, 0.35f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.13f, 0.13f, 0.13f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.09f, 0.15f, 0.16f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.15f, 0.60f, 0.78f, 0.78f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.24f, 0.40f, 0.95f, 1.00f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.40f, 0.95f, 0.59f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.24f, 0.40f, 0.95f, 1.00f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.24f, 0.40f, 0.95f, 0.59f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
}

void styled()
{
	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowRounding = 0.f;
	style.FramePadding = ImVec2(4, 0);
	style.WindowPadding = ImVec2(0, 0);
	style.ItemSpacing = ImVec2(0, 0);
	style.ScrollbarSize = 10.f;
	style.ScrollbarRounding = 0.f;
	style.GrabMinSize = 5.f;
}

void ButtonColor(int r, int g, int b)
{
	ImGuiStyle& style = ImGui::GetStyle();

	style.Colors[ImGuiCol_Button] = ImColor(r, g, b);
	style.Colors[ImGuiCol_ButtonHovered] = ImColor(r, g, b);
	style.Colors[ImGuiCol_ButtonActive] = ImColor(r, g, b);
}

void Gui::Render()
{
	ImGuiIO& io = ImGui::GetIO();
	ImGuiStyle& style = ImGui::GetStyle();

	ImVec2 pos;

	style.Colors[ImGuiCol_Text] = ImVec4(0.86f, 0.93f, 0.89f, 0.78f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.86f, 0.93f, 0.89f, 0.78f);
	style.Colors[ImGuiCol_WindowBg] = ImColor(15, 15, 15, 255);
	style.Colors[ImGuiCol_Border] = ImColor(15, 15, 15, 255);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.09f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.04f, 0.04f, 0.04f, 0.88f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.20f, 0.22f, 0.27f, 0.75f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.35f, 0.35f, 0.35f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.13f, 0.13f, 0.13f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.09f, 0.15f, 0.16f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.15f, 0.60f, 0.78f, 0.78f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.24f, 0.40f, 0.95f, 1.00f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.40f, 0.95f, 0.59f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.24f, 0.40f, 0.95f, 1.00f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.24f, 0.40f, 0.95f, 0.59f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);

	ImGui::SetNextWindowSize(ImVec2(840, 560));
	ImGui::Begin("EzTap", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar);
	{

		pos = ImGui::GetWindowPos();

		ImGui::Columns(2, nullptr, false);
		ImGui::SetColumnOffset(1, 135);

		ButtonColor(15, 15, 15);
		ImGui::Button("##upprtabs", ImVec2(114, 20));

		ImGui::SameLine();
		styled();
		color();
		ButtonColor(50, 50, 50);
		ImGui::Button("##rageupline", ImVec2(1, 20));

		/*rage*/
		{
			if (iTab == 0) ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##rageupline", ImVec2(118, 1));

			ImGui::SameLine();

			ButtonColor(50, 50, 50);
			ImGui::Button("##fgfgfg", ImVec2(1, 1));

			ButtonColor(15, 15, 15);
			if (iTab == 0) style.Colors[ImGuiCol_Text] = ImColor(200, 200, 200); else style.Colors[ImGuiCol_Text] = ImColor(80, 80, 80);
			ImGui::PushFont(IconFont);
			if (ImGui::Button("A", ImVec2(118, 100))) iTab = 0;
			ImGui::PopFont();

			ImGui::SameLine();

			if (iTab != 0)ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##gfgfgfgfgfgf", ImVec2(1, 100));

			if (iTab == 0) ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##ragedownline", ImVec2(118, 1));

			ImGui::SameLine();

			ButtonColor(50, 50, 50);
			ImGui::Button("##fgfgfg", ImVec2(1, 1));

		}

		/*legit*/
		{
			if (iTab == 1) ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##lupline", ImVec2(118, 1));

			ImGui::SameLine();

			ButtonColor(50, 50, 50);
			ImGui::Button("##fgfgfg", ImVec2(1, 1));

			ButtonColor(15, 15, 15);
			if (iTab == 1) style.Colors[ImGuiCol_Text] = ImColor(200, 200, 200); else style.Colors[ImGuiCol_Text] = ImColor(80, 80, 80);
			ImGui::PushFont(IconFont);
			if (ImGui::Button("B", ImVec2(118, 100))) iTab = 1;
			ImGui::PopFont();
			ImGui::SameLine();

			if (iTab != 1)ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##gfgfgfgfgfgf", ImVec2(1, 100));

			if (iTab == 1) ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##ldownline", ImVec2(118, 1));

			ImGui::SameLine();

			ButtonColor(50, 50, 50);
			ImGui::Button("##fgfgfg", ImVec2(1, 1));
		}

		/*visuals*/
		{
			if (iTab == 2) ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##vupline", ImVec2(118, 1));

			ImGui::SameLine();

			ButtonColor(50, 50, 50);
			ImGui::Button("##fgfgfg", ImVec2(1, 1));

			ButtonColor(15, 15, 15);
			if (iTab == 2) style.Colors[ImGuiCol_Text] = ImColor(200, 200, 200); else style.Colors[ImGuiCol_Text] = ImColor(80, 80, 80);
			ImGui::PushFont(IconFont);
			if (ImGui::Button("C", ImVec2(118, 100))) iTab = 2;
			ImGui::PopFont();
			ImGui::SameLine();

			if (iTab != 2)ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##gfgfgfgfgfgf", ImVec2(1, 100));

			if (iTab == 2) ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##vdownline", ImVec2(118, 1));

			ImGui::SameLine();

			ButtonColor(50, 50, 50);
			ImGui::Button("##fgfgfg", ImVec2(1, 1));
		}

		/*misc*/
		{
			if (iTab == 3) ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##mupline", ImVec2(118, 1));

			ImGui::SameLine();

			ButtonColor(50, 50, 50);
			ImGui::Button("##fgfgfg", ImVec2(1, 1));

			ButtonColor(15, 15, 15);
			if (iTab == 3) style.Colors[ImGuiCol_Text] = ImColor(200, 200, 200); else style.Colors[ImGuiCol_Text] = ImColor(80, 80, 80);
			ImGui::PushFont(IconFont);
			if (ImGui::Button("D", ImVec2(118, 100))) iTab = 3;
			ImGui::PopFont();
			ImGui::SameLine();

			if (iTab != 3)ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##gfgfgfgfgfgf", ImVec2(1, 100));

			if (iTab == 3) ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##mdownline", ImVec2(118, 1));

			ImGui::SameLine();

			ButtonColor(50, 50, 50);
			ImGui::Button("##fgfgfg", ImVec2(1, 1));
		}

		/*skins*/
		{
			if (iTab == 4) ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##supline", ImVec2(118, 1));

			ImGui::SameLine();

			ButtonColor(50, 50, 50);
			ImGui::Button("##fgfgfg", ImVec2(1, 1));

			ButtonColor(15, 15, 15);
			if (iTab == 4) style.Colors[ImGuiCol_Text] = ImColor(200, 200, 200); else style.Colors[ImGuiCol_Text] = ImColor(80, 80, 80);
			ImGui::PushFont(IconFont);
			if (ImGui::Button("E", ImVec2(118, 100))) iTab = 4;
			ImGui::PopFont();
			ImGui::SameLine();

			if (iTab != 4)ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##gfgfgfgfgfgf", ImVec2(1, 100));

			if (iTab == 4) ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##sdownline", ImVec2(118, 1));

			ImGui::SameLine();

			ButtonColor(50, 50, 50);
			ImGui::Button("##fgfgfg", ImVec2(1, 1));
		}

		/*configs*/
		{
			if (iTab == 5) ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##supline", ImVec2(118, 1));

			ImGui::SameLine();

			ButtonColor(50, 50, 50);
			ImGui::Button("##fgfgfg", ImVec2(1, 1));

			ButtonColor(15, 15, 15);
			if (iTab == 5) style.Colors[ImGuiCol_Text] = ImColor(200, 200, 200); else style.Colors[ImGuiCol_Text] = ImColor(80, 80, 80);
			ImGui::PushFont(IconFont);
			if (ImGui::Button("H", ImVec2(118, 100))) iTab = 5;
			ImGui::PopFont();
			ImGui::SameLine();

			if (iTab != 5)ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##gfgfgfgfgfgf", ImVec2(1, 100));

			if (iTab == 5) ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##sdownline", ImVec2(118, 1));

			ImGui::SameLine();

			ButtonColor(50, 50, 50);
			ImGui::Button("##fgfgfg", ImVec2(1, 1));
		}

		/*lua*/
		{
			if (iTab == 6) ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##supline", ImVec2(118, 1));

			ImGui::SameLine();

			ButtonColor(50, 50, 50);
			ImGui::Button("##fgfgfg", ImVec2(1, 1));

			ButtonColor(15, 15, 15);
			if (iTab == 6) style.Colors[ImGuiCol_Text] = ImColor(200, 200, 200); else style.Colors[ImGuiCol_Text] = ImColor(80, 80, 80);
			ImGui::PushFont(IconFont);
			if (ImGui::Button("I", ImVec2(118, 100))) iTab = 6;
			ImGui::PopFont();
			ImGui::SameLine();

			if (iTab != 6)ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##gfgfgfgfgfgf", ImVec2(1, 100));

			if (iTab == 6) ButtonColor(50, 50, 50); else ButtonColor(15, 15, 15);
			ImGui::Button("##sdownline", ImVec2(118, 1));

			ImGui::SameLine();

			ButtonColor(50, 50, 50);
			ImGui::Button("##fgfgfg", ImVec2(1, 1));
		}

		ButtonColor(15, 15, 15);
		ImGui::Button("##upprtabs", ImVec2(118, 20));

		ImGui::SameLine();

		ButtonColor(50, 50, 50);
		ImGui::Button("##rageupline", ImVec2(1, 20));

		ImGui::NextColumn();
		style.WindowPadding = ImVec2(8, 8);
		style.ItemSpacing = ImVec2(4, 4);
		style.Colors[ImGuiCol_Text] = ImVec4(0.86f, 0.93f, 0.89f, 0.78f);
		style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.86f, 0.93f, 0.89f, 0.78f);
		style.Colors[ImGuiCol_WindowBg] = ImColor(15, 15, 15, 255);
		style.Colors[ImGuiCol_Border] = ImColor(15, 15, 15, 255);
		style.Colors[ImGuiCol_FrameBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.09f);
		style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
		style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.04f, 0.04f, 0.04f, 0.88f);
		style.Colors[ImGuiCol_TitleBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
		style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.20f, 0.22f, 0.27f, 0.75f);
		style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.35f, 0.35f, 0.35f, 1.00f);
		style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.13f, 0.13f, 0.13f, 1.00f);
		style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.09f, 0.15f, 0.16f, 1.00f);
		style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.15f, 0.60f, 0.78f, 0.78f);
		style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_Button] = ImVec4(0.24f, 0.40f, 0.95f, 1.00f);
		style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.40f, 0.95f, 0.59f);
		style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
		style.Colors[ImGuiCol_Header] = ImVec4(0.24f, 0.40f, 0.95f, 1.00f);
		style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.24f, 0.40f, 0.95f, 0.59f);
		style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
		ImGui::BeginChild("main", ImVec2(700, 540));
		{
			if (iTab == 0) RenderTab1();
			if (iTab == 1) RenderTab2();
			if (iTab == 2) RenderTab3();
			if (iTab == 3) RenderTab4();
			if (iTab == 4) RenderTab5();
			if (iTab == 5) RenderTab6();
			if (iTab == 6) RenderTab7();
		}ImGui::EndChild();

	}
	ImGui::End();

	style.Colors[ImGuiCol_WindowBg] = ImColor(30, 30, 30, 255);
	ImGui::SetNextWindowPos(ImVec2(pos.x - 4, pos.y - 4));
	ImGui::SetNextWindowSize(ImVec2(848, 568));
	ImGui::Begin("borderr", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBringToFrontOnFocus);
	{

	}ImGui::End();

}

void Gui::Watermark()
{
	if (!drawList)
		return;

	static char username[UNLEN + 1];
	static bool set = false;
	if (!set)
	{
		set = true;
		DWORD uname_len = UNLEN + 1;
		GetUserName(username, &uname_len);
	}

	drawList->AddRectFilled({ 10, 10 }, { 250, 60 }, ImColor(.1f, .1f, .1f, 1.f), 0.2f);
	drawList->AddRectFilled({ 10, 10 }, { 250, 15 }, ImColor(204, 27, 207), 0.2f);

	drawList->AddText({ 15, 20 }, ImColor(1.f, 1.f, 1.f), ("Build: " + std::string(__DATE__) + " (PRIVATE)").c_str());
	drawList->AddText({ 15, 37.5 }, ImColor(204, 27, 207), username);
}

//Rage Bot
void Gui::RenderTab1()
{
	ImGui::FancyCheckbox("Aimbot##aimbotbtn", &features.Aimbot);
	ImGui::FancyCheckbox("Auto Wall", &features.Autowall);
	ImGui::FancyCheckbox("Auto Fire", &features.Aimbot_AutoFire);
	ImGui::FancyCheckbox("Auto Scope", &features.Aimbot_AutoScope);
	ImGui::FancyCheckbox("Silent", &features.Aimbot_Silent);
	ImGui::SliderFloat("Aim FOV", &features.Aimbot_FOV, 1, 180);
	ImGui::SliderInt("Min Damage", &features.AutowallMinDmg, 1, 200);
}

//Legit bot
void Gui::RenderTab2()
{
	ImGui::FancyCheckbox("Triggerbot", &features.Legit_Triggerbot);
	ImGui::FancyCheckbox("Radar Hack", &features.Legit_RadarHack);
}

//Visuals
void Gui::RenderTab3()
{
	ImGui::FancyCheckbox("Chams", &features.Chams);
	ImGui::FancyCheckbox("Arm Chams", &features.Chams_Arms);
	ImGui::FancyCheckbox("Wireframe Arms", &features.Chams_Arms_Wireframe);

	ImGui::Spacing();

	ImGui::FancyCheckbox("Box Esp", &features.BoxEsp);
	ImGui::FancyCheckbox("Box Esp Name", &features.BoxEspName);
	ImGui::FancyCheckbox("Box Esp Health", &features.BoxEspHealth);
	ImGui::FancyCheckbox("Box Esp Armor", &features.BoxEspArmor);
}

// Settings/Misc
void Gui::RenderTab4()
{
	ImGui::FancyCheckbox("Disable Panorama Blur", &features.NoPanoramaBlur);
	ImGui::FancyCheckbox("No Hands", &features.NoHands);
	ImGui::FancyCheckbox("Bunnyhop", &features.Bunnyhop);
	ImGui::FancyCheckbox("Force Crosshair", &features.ForceCrosshair);
	ImGui::FancyCheckbox("Rank Reveal", &features.RankReveal);
	ImGui::FancyCheckbox("No Flash", &features.NoFlash);
	ImGui::FancyCheckbox("Auto Accept", &features.AutoAccept);
	ImGui::FancyCheckbox("Clan Tag", &features.ClanTag);
	ImGui::FancyCheckbox("Trash Talk", &features.TrashTalk);
	ImGui::SliderInt("FOV", &features.FOV, 60, 160);
}

// Skin Changer
void Gui::RenderTab5()
{
	ImGui::Text("To be added...");
}

// Configs
void Gui::RenderTab6()
{

}

std::vector<std::string> luaList;
void ReloadLuas()
{
	luaList.clear();
	luaList.empty();

	for (const auto& entry : std::filesystem::directory_iterator("EzTap\\LUA"))
	{
		static std::stringstream ss;
		ss.str("");
		ss << entry.path().filename().string();
		luaList.push_back(ss.str());
	}
}

// Lua
static int selectedLua = 0;
static int selectedActiveLua = 0;
static int selectedActiveLua1 = 0;
void Gui::RenderTab7()
{
	static bool initLua = true;
	if (initLua) { ReloadLuas(); initLua = false; }

	if (ImGui::ListBoxHeader("Avalible LUAs"))
	{
		for (int i = 0; i < luaList.size(); i++)
		{
			std::string script = luaList.at(i);

			if (ImGui::Selectable(script.c_str(), (i == selectedLua)))
				selectedLua = i;
		}

		ImGui::ListBoxFooter();
	}

	if (ImGui::Button("Execute LUA"))
	{
		static char fnameBuf[MAX_PATH];
		sprintf(fnameBuf, "EzTap\\LUA\\%s", luaList.at(selectedLua).c_str());
		g_pLuaEngine->ExecuteFile(fnameBuf);
	}

	ImGui::SameLine();

	if (ImGui::Button("Refresh LUAs"))
		ReloadLuas();
}
