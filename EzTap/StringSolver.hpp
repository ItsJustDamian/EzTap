#pragma once
#include <sstream>

namespace StringSolver
{
	inline const char * SolveCharArray(std::vector<char> a)
	{
		std::stringstream ss;
		for (size_t i = 0; i < a.size(); i++)
		{
			ss << a.at(i);
		}
		return ss.str().c_str();
	}
}