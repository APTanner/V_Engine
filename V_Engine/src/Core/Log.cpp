#include "Log.h"

namespace V_Engine
{
	Simple_Logger::Logger Log::logger;

	void Log::init()
	{
		logger = Simple_Logger::Logger();
		logger.init();
	}
}
