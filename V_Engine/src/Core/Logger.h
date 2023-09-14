#pragma once

#include <Windows.h>
#include <string>

#include "fOutput/fOutput.h"

namespace V_Engine
{
	class Logger
	{
	public:
		enum class LogLevel : int
		{
			debug,
			warning,
			error
		};

		static void init();

		static void setLevel(const LogLevel level);

		template<typename ... Args>
		static void debug(const char* const format, const Args& ... args)
		{
			log(LogLevel::debug, format, args ...);
		}

		template<typename ... Args>
		static void debug(const wchar_t* const format, const Args& ... args)
		{
			log(LogLevel::debug, format, args ...);
		}

		template<typename ... Args>
		static void warning(const char* const format, const Args& ... args)
		{
			log(LogLevel::warning, format, args ...);
		}

		template<typename ... Args>
		static void warning(const wchar_t* const format, const Args& ... args)
		{
			log(LogLevel::warning, format, args ...);
		}

		template<typename ... Args>
		static void error(const char* const format, const Args& ... args)
		{
			log(LogLevel::error, format, args ...);
		}

		template<typename ... Args>
		static void error(const wchar_t* const format, const Args& ... args)
		{
			log(LogLevel::error, format, args ...);
		}
	private:
		static LogLevel m_level;
		static HANDLE m_hConsole;

		template<typename T>
		static void logPrefix(std::basic_string<T>& buffer, const LogLevel level)
		{
			// TODO other stuff here in the future (timing/file and location)
			fOutput::format(buffer, "[%s] ", getLevelName(level));
		}

		static const std::string getLevelName(const LogLevel level)
		{
			switch (level)
			{
			case LogLevel::debug:   return "DEBUG";
			case LogLevel::warning: return "WARNING";
			case LogLevel::error:   return "ERROR";
			default:				return "UNKNOWN";
			}
		}

		static void setConsoleColor(const LogLevel level)
		{
			switch (level)
			{
			case LogLevel::debug:
				SetConsoleTextAttribute(m_hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				break;
			case LogLevel::warning:
				SetConsoleTextAttribute(m_hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
				break;
			case LogLevel::error:
				SetConsoleTextAttribute(m_hConsole, FOREGROUND_RED);
				break;
			default:
				SetConsoleTextAttribute(m_hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
		}

		static void clearConsoleColor()
		{
			SetConsoleTextAttribute(m_hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		
		template<typename T, typename ... Args>
		static void log(const LogLevel level, const T* format, const Args& ... args)
		{
			if (m_level > level)
				return;
			std::basic_string<T> buffer;
			// append the stuff around the message
			logPrefix(buffer, level);
			buffer += format;
			buffer += '\n';
			setConsoleColor(level);
			fOutput::print(buffer, args ...);
			clearConsoleColor();
		}
	};
}

