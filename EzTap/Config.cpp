#include "Config.hpp"

/*

	file layout:
	key=value

*/

void CONFIG::Init(const char* filename)
{
	file.open(filename);
	Reload();
}

void CONFIG::Save()
{
}

void CONFIG::Reload()
{
	kvArray.clear();
	kvArray.empty();

	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string k, v;
		if (!(iss >> k >> v)) break;
		kvArray.push_back(std::pair<std::string,std::string >(k, v));
	}
}
