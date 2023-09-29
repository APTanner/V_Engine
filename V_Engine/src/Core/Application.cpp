#include "pch.h"
#include "Application.h"

#include "Events/WindowEvent.h"


namespace V_Engine
{
	Application::Application()
	{
		// initialization
		Log::init();
		m_window = std::unique_ptr<Window>(GLFWManager::InstantiateWindow());
		m_window->SetEventCallback([this](Event& e)
		{
			this->OnEvent(e);
		});
	}

	Application::~Application()
	{
		GLFWManager::Shutdown();
	}

	void Application::Run()
	{
		while (m_running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& event)
	{
		LOG_DEBUG(event.ToString());
		EventDispatcher d(event);
		d.Dispatch<WindowCloseEvent>([this](const WindowCloseEvent& event) -> bool
			{ return this->OnWindowClose(event); });
	}

	bool Application::OnWindowClose(const WindowCloseEvent& event)
	{
		m_running = false;
		return true;
	}
}
