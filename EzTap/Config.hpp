#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class CONFIG
{
private:
	const char* filename;
	std::vector<std::pair<std::string, std::string>> kvArray;
	std::ifstream file;
public:
	void Init(const char* filename);
	void Save();
	void Reload();
};