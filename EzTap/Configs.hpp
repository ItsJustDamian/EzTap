#pragma once
#include <iostream>
#include <fstream>
#include "ini.h"
#include "Globals.hpp"

class Configs
{
public:
	Configs(const char* fname) { filename = fname; };
	~Configs() {  }

	void ReadSettings();
	void SaveSettings();
private:
	const char * filename;
};

