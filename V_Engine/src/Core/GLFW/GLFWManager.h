#pragma once
#include "pch.h"
#include "Core/Log.h"
#include "Core/GLFW/Window.h"

namespace V_Engine
{
	class GLFWManager
	{
	public:
		//create static only class
		GLFWManager() = delete;
		GLFWManager(const GLFWManager&) = delete;
		GLFWManager(GLFWManager&&) = delete;

		static std::unique_ptr<Window> InstantiateWindow(const Window::Data& windowData = Window::Data());
		static void Shutdown();
	private:

		static bool s_GLFWInitialized;
	};
}

