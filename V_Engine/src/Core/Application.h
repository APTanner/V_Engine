#pragma once
#include "pch.h"

#include "Log.h"
#include "Events/WindowEvent.h"
#include "Core/GLFW/GLFWManager.h"

namespace V_Engine
{
	class Application
	{
	public:
		Application();
		~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_window;
	};
}

