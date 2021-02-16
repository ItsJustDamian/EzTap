#include "LoginGui.hpp"

void LoginGui::Render()
{
	static int screenWidth, screenHeight;
	if (!screenWidth || !screenHeight)
		interfaces.Engine->getScreenSize(&screenWidth, &screenHeight);

	ImGuiStyle& style = ImGui::GetStyle();

	style.Colors[ImGuiCol_Button] = ImVec4(0.8f, 0.1f, 0.81f, 1.00f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.8f, 0.1f, 0.61f, 1.00f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.8f, 0.1f, 0.71f, 1.00f);
	style.Colors[ImGuiCol_Text] = ImVec4(1.f, 1.f, 1.f, 1.00f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.8f, 0.1f, 0.81f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.8f, 0.1f, 0.81f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.8f, 0.1f, 0.81f, 1.00f);

	drawList->AddRectFilled({ 0, 0 }, { (float)screenWidth, (float)screenHeight }, ImColor(0, 0, 0, 175));

	ImGui::SetNextWindowSize(ImVec2(300, 150));
	ImGui::SetNextWindowPos(ImVec2{ (float)screenWidth / 2 - 150, (float)screenHeight / 2 - 75 });
	if (ImGui::Begin("Login EzTap ## LoginGui", 0, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize))
	{
		static char username[128], password[128];

		ImGui::Text("Username:");
		ImGui::InputText("##iUsername", username, 128);
		ImGui::Text("Password:");
		ImGui::InputText("##iPassword", password, 128, ImGuiInputTextFlags_Password);
		if (ImGui::Button("Login"))
		{
			MELikEYCheeSE = true;
			interfaces.GameUI->createCmdMsgBox("Welcome back!", "Yeah, not finished yet, im lazy :)");
		}

		ImGui::SameLine();

		if (ImGui::Button("Fuck this"))
			features.EjectCheat = true;

		ImGui::End();
	}
}
