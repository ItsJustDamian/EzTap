#include "Configs.hpp"

void Configs::ReadSettings()
{
	if (filename == nullptr)
	{
		console.Error("Config filename is nullptr!\n");
		return;
	}

	mINI::INIFile file(filename);
	mINI::INIStructure cfg;
	
	if (!file.read(cfg))
	{
		console.Error("Failed to read config!\n");
		return;
	}

	//ReadConfigObj(bool, Aimbot, "Aimbot", "Enabled");

}

void Configs::SaveSettings()
{
	if (filename == nullptr)
	{
		console.Error("Config filename is nullptr!\n");
		return;
	}
}
