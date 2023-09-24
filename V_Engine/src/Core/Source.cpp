#include "Log.h"

namespace V_Engine
{
	int main()
	{
		Log::init();
		int a = 1;
		LOG_DEBUG("Testing, a is %i and also %i", a);
		LOG_ERROR("Problem");
		LOG_WARNING("Something wrong but it works for now");
		return 0;
	}
}

int main()
{
	return V_Engine::main();
}