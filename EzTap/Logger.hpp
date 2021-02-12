#pragma once
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>

class Logger
{
public:
	Logger(const char* filename = nullptr)
	{
		if (!filename)
		{
			auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
			std::string sfn = std::ctime(&now);
			sfn.append(".txt");
			filename = sfn.c_str();
		}

		lFilename = filename;
		lFile.open(lFilename, std::ios_base::app);
	}
	~Logger()
	{
		lFile.close();
	}
	void append(const char* fmt, ...)
	{
		char buffer[2048];

		va_list _ArgList;
		__crt_va_start(_ArgList, fmt);

		#pragma warning(push)
		#pragma warning(disable: 4996)
				_vsprintf_l(buffer, fmt, NULL, _ArgList);
		#pragma warning(pop)

		__crt_va_end(_ArgList);


		char s[256];
		time_t t = time(NULL);
		struct tm* p = localtime(&t);
		strftime(s, 256, "%d-%m-%Y - %R", p);

		lFile << "[" << s << "]: " << buffer << "\n";
	}

	void sappend(const char* fmt, ...)
	{
		char buffer[2048];

		va_list _ArgList;
		__crt_va_start(_ArgList, fmt);

		#pragma warning(push)
		#pragma warning(disable: 4996)
		_vsprintf_l(buffer, fmt, NULL, _ArgList);
		#pragma warning(pop)

		__crt_va_end(_ArgList);


		char s[256];
		time_t t = time(NULL);
		struct tm* p = localtime(&t);
		strftime(s, 256, "%d-%m-%Y - %R", p);

		lFile << "[" << s << "]: " << buffer;
	}

private:
	std::fstream lFile;
	const char* lFilename = nullptr;
};

inline Logger* logs = new Logger("EzTap\\LOGS\\Logs.txt");
inline Logger* debugLogs = new Logger("EzTap\\LOGS\\DebugLogs.txt");
inline Logger* errorLogs = new Logger("EzTap\\LOGS\\ErrorLogs.txt");
