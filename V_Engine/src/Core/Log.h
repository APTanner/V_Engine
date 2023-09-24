#pragma once

#include "Simple_Logger/Simple_Logger.h"

namespace V_Engine
{
	class Log
	{
	public:
		static void init();

		inline static Simple_Logger::Logger& getLogger() { return logger; }
	private:
		static Simple_Logger::Logger logger;
	};
}

#define LOG_DEBUG(...) Log::getLogger().debug(__VA_ARGS__)
#define LOG_WARNING(...) Log::getLogger().warning(__VA_ARGS__)
#define LOG_ERROR(...) Log::getLogger().error(__VA_ARGS__)


