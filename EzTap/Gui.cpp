#include "Gui.hpp"

void Gui::Render()
{
	ImGui::SetNextWindowSize(ImVec2(400, 300));
	if (ImGui::Begin("EzTap"))
	{
		if (ImGui::BeginTabBar("##featurescats"))
		{
			if (ImGui::BeginTabItem("Visuals"))
			{
				ImGui::FancyCheckbox("Chams", &features.Chams);
				ImGui::FancyCheckbox("Arm Chams", &features.Chams_Arms);
				ImGui::FancyCheckbox("Wireframe Arms", &features.Chams_Arms_Wireframe);

				ImGui::Spacing();

				ImGui::FancyCheckbox("Box Esp", &features.BoxEsp);
				ImGui::FancyCheckbox("Box Esp Name", &features.BoxEspName);
				ImGui::FancyCheckbox("Box Esp Health", &features.BoxEspHealth);
				ImGui::FancyCheckbox("Box Esp Armor", &features.BoxEspArmor);
				
				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Aimbot"))
			{
				ImGui::FancyCheckbox("Aimbot##aimbotbtn", &features.Aimbot);
				ImGui::FancyCheckbox("Auto Wall", &features.Autowall);
				ImGui::FancyCheckbox("Auto Fire", &features.Aimbot_AutoFire);
				ImGui::FancyCheckbox("Auto Scope", &features.Aimbot_AutoScope);
				ImGui::FancyCheckbox("Silent", &features.Aimbot_Silent);
				ImGui::SliderFloat("Aim FOV", &features.Aimbot_FOV, 1, 180);
				ImGui::SliderInt("Min Damage", &features.AutowallMinDmg, 1, 200);

				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Misc"))
			{
				ImGui::FancyCheckbox("Disable Panorama Blur", &features.NoPanoramaBlur);
				ImGui::FancyCheckbox("No Hands", &features.NoHands);
				ImGui::FancyCheckbox("Bunnyhop", &features.Bunnyhop);
				ImGui::FancyCheckbox("Force Crosshair", &features.ForceCrosshair);
				ImGui::FancyCheckbox("Rank Reveal", &features.RankReveal);
				ImGui::FancyCheckbox("No Flash", &features.NoFlash);
				ImGui::SliderInt("FOV", &features.FOV, 60, 160);

				ImGui::EndTabItem();
			}

			ImGui::EndTabBar();
		}

		ImGui::End();
	}
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
