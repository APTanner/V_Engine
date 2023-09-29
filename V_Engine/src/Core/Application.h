#pragma once
#include "pch.h"

#include "Log.h"
#include "Core/GLFW/GLFWManager.h"
#include "Core/Events/WindowEvent.h"

namespace V_Engine
{
	class Application
	{
	public:
		Application();
		~Application();

		void Run();

		void OnEvent(Event& event);
		bool OnWindowClose(const WindowCloseEvent& event);
	private:
		std::unique_ptr<Window> m_window;
		bool m_running = true;
	};
}

