#include "Logger.h"

namespace V_Engine
{
	int main()
	{
		Logger::init();
		int a = 1;
		Logger::debug("Testing, a is %i", a);
		Logger::error("Problem");
		Logger::warning("Something wrong but it works for now");
		return 0;
	}
}

int main()
{
	return V_Engine::main();
}