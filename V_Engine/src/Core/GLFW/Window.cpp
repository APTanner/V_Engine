#include "pch.h"
#include "Window.h"

#include "Core/Log.h"

namespace V_Engine
{
	Window::Window(Window::Data data)
	{
		m_data = data;
		LOG_DEBUG("Creating Window %s (%u, %u)", data.Title, data.Width, data.Height);
		m_window = glfwCreateWindow((int)data.Width, (int)data.Height, data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, &m_data);
		SetVSync(data.VSync);
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_window);
	}

	void Window::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	void Window::SetVSync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		m_data.VSync = enabled;
	}

	bool Window::IsVSync() const { return m_data.VSync; }
}