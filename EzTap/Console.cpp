#include "Console.hpp"
#pragma warning(disable:4996)

const std::string Console::GetCurrentDateTime()
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

	return buf;
}

void Console::Init(const char * consoleName, bool isDebug)
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);
	SetConsoleTitle(consoleName);
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	debug = isDebug;
	ready = true;
}

void Console::Close()
{
	ready = false;
	FreeConsole();
}

std::string Console::Read(const char* prefix, char mask)
{
	if (mask == NULL) {
		Write(prefix);
		std::string line;
		std::getline(std::cin, line);
		return line;
	}
	else {
		const char BACKSPACE = 8;
		const char RETURN = 13;

		std::string line;
		unsigned char ch = 0;

		Write(prefix);

		DWORD con_mode;
		DWORD dwRead;

		HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

		GetConsoleMode(hIn, &con_mode);
		SetConsoleMode(hIn, con_mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

		while (ReadConsoleA(hIn, &ch, 1, &dwRead, NULL) && ch != RETURN)
		{
			if (ch == BACKSPACE)
			{
				if (line.length() != 0)
				{
					Write("\b \b");
					line.resize(line.length() - 1);
				}
			}
			else
			{
				line += ch;
				Write("%c", mask);
			}
		}
		Write("\n");
		SetConsoleMode(hIn, con_mode);
		return line;
	}
}

void Console::Write(const char * fmt, ...)
{
	if (!ready)
		return;

	char buffer[2048];

	va_list _ArgList;
	__crt_va_start(_ArgList, fmt);

	#pragma warning(push)
	#pragma warning(disable: 4996)
	_vsprintf_l(buffer, fmt, NULL, _ArgList);
	#pragma warning(pop)

	__crt_va_end(_ArgList);

	SetConsoleTextAttribute(consoleHandle, 7); //Set to white
	std::cout << buffer;
}

void Console::Info(const char * fmt, ...)
{
	if (!ready)
		return;

	char buffer[2048];

	va_list _ArgList;
	__crt_va_start(_ArgList, fmt);

	#pragma warning(push)
	#pragma warning(disable: 4996)
	_vsprintf_l(buffer, fmt, NULL, _ArgList);
	#pragma warning(pop)

	__crt_va_end(_ArgList);

	SetConsoleTextAttribute(consoleHandle, 7);
	std::cout << "[x] " << buffer;

	logs->append(buffer);
}

void Console::Warning(const char * fmt, ...)
{
	if (!ready)
		return;

	char buffer[2048];

	va_list _ArgList;
	__crt_va_start(_ArgList, fmt);

	#pragma warning(push)
	#pragma warning(disable: 4996)
	_vsprintf_l(buffer, fmt, NULL, _ArgList);
	#pragma warning(pop)

	__crt_va_end(_ArgList);

	SetConsoleTextAttribute(consoleHandle, 14);
	std::cout << "[x] ";
	SetConsoleTextAttribute(consoleHandle, 7);
	std::cout << buffer;

	logs->append(buffer);
}

void Console::Error(const char * fmt, ...)
{
	if (!ready)
		return;

	char buffer[2048];

	va_list _ArgList;
	__crt_va_start(_ArgList, fmt);

	#pragma warning(push)
	#pragma warning(disable: 4996)
	_vsprintf_l(buffer, fmt, NULL, _ArgList);
	#pragma warning(pop)

	__crt_va_end(_ArgList);

	SetConsoleTextAttribute(consoleHandle, 4);
	std::cout << "[x] ";
	SetConsoleTextAttribute(consoleHandle, 7);
	std::cout << buffer;

	errorLogs->append(buffer);
}

void Console::Debug(const char * fmt, ...)
{
	if (!ready || !debug)
		return;

	char buffer[2048];

	va_list _ArgList;
	__crt_va_start(_ArgList, fmt);

	#pragma warning(push)
	#pragma warning(disable: 4996)
	_vsprintf_l(buffer, fmt, NULL, _ArgList);
	#pragma warning(pop)

	__crt_va_end(_ArgList);

	SetConsoleTextAttribute(consoleHandle, 5);
	std::cout << "[x] ";
	SetConsoleTextAttribute(consoleHandle, 7);
	std::cout << buffer;

	debugLogs->append(buffer);
}
