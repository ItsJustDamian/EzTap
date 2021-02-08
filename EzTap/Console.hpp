#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
#include <ctime>

class Console
{
private:
	bool debug = false;
	bool ready = false;
	HANDLE consoleHandle;
public:
	const std::string GetCurrentDateTime();
	void Init(const char * consoleName, bool isDebug = false);
	void Close();
	std::string Read(const char* prefix = ">> ", char mask = NULL);
	void Write(const char * fmt, ...);
	void Info(const char * fmt, ...);
	void Warning(const char * fmt, ...);
	void Error(const char * fmt, ...);
	void Debug(const char * fmt, ...);
} inline console;