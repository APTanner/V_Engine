#include "pch.h"
#include "Window.h"

#include "Core/Log.h"

namespace V_Engine
{
	bool Window::s_GLFWInitialized;

	Window::Window(Window::Data data)
	{
		m_data = data;

		LOG_DEBUG("Creating Window %s (%u, %u)", data.Title, data.Width, data.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			if (!success)
			{
				LOG_ERROR("GLFW not initialized");
			}

			m_window = glfwCreateWindow((int)data.Width, (int)data.Height, data.Title.c_str(), nullptr, nullptr);)
			glfwMakeContextCurrent(m_window);
			glfwSetWindowUserPointer(m_window, &m_data);
			SetVSync(data.VSync);
		}
	}
}