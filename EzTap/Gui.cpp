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
	ImGui::Begin("skeetttt", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar);
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
			if (iTab == 0)
			{
				static int kanker = 0;
				ImGui::SliderInt("Kanker", &kanker, 0, 100);
			}
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
