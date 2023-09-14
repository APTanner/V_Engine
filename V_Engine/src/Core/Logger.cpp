#include "Logger.h"

namespace V_Engine
{
	Logger::LogLevel Logger::m_level{};
	HANDLE Logger::m_hConsole{};

	void Logger::init()
	{
		setLevel(Logger::LogLevel::debug);
		m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	void Logger::setLevel(const Logger::LogLevel level)
	{
		m_level = level;
	}
}