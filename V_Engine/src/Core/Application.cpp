#include "pch.h"
#include "Application.h"

namespace V_Engine
{
	Application::Application()
	{
		Log::init();
		m_window = std::unique_ptr<Window>(GLFWManager::InstantiateWindow());
	}

	Application::~Application()
	{
		GLFWManager::Shutdown();
	}

	void Application::Run()
	{
		int a = 1;
		LOG_DEBUG("Testing, a is %i and also %i", a);
		LOG_ERROR("Problem");
		LOG_WARNING("Something wrong but it works for now");

		WindowResizeEvent e(10, 10);
		if (e.IsInCategory(WindowCategoryEvent))
		{
			LOG_DEBUG(e.ToString());
		}

		while (true);
	}
}
