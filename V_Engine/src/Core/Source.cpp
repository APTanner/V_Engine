#include "pch.h"
#include "Log.h"
#include "Events/WindowEvent.h"

namespace V_Engine
{
	int main()
	{
		Log::init();
		int a = 1;
		LOG_DEBUG("Testing, a is %i and also %i", a);
		LOG_ERROR("Problem");
		LOG_WARNING("Something wrong but it works for now");

		WindowResizeEvent e(10, 10);
		if (e.IsInCategory(WindowCategoryEvent))
		{
			LOG_DEBUG(e.ToString());
		}

		return 0;
	}
}

int main()
{
	return V_Engine::main();
}