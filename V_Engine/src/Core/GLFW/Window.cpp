#include "pch.h"
#include "Window.h"

#include "Core/Log.h"
#include "Core/Events/KeyEvent.h"
#include "Core/Events/MouseEvent.h"
#include "Core/Events/WindowEvent.h"



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

	void Window::SetCallbacks()
	{
		// set GLFW Callbacks
		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				Data* data = static_cast<Data*>(glfwGetWindowUserPointer(window));

				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data->EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data->EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data->EventCallback(event);
					break;
				}
				}
			});
		
		glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
			{
				Data* data = static_cast<Data*>(glfwGetWindowUserPointer(window));

				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressEvent event(button);
					data->EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleaseEvent event(button);
					data->EventCallback(event);
					break;
				}
				}
			});
		glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos)
			{
				Data* data = static_cast<Data*>(glfwGetWindowUserPointer(window));

				MouseMoveEvent event((float)xPos, (float)yPos);
				data->EventCallback(event);
			});
		glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				Data* data = static_cast<Data*>(glfwGetWindowUserPointer(window));

				MouseScrollEvent event((float)xOffset, (float)yOffset);
				data->EventCallback(event);
			});

		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
			{
				Data* data = static_cast<Data*>(glfwGetWindowUserPointer(window));
				data->Width = width;
				data->Height = height;

				WindowResizeEvent event(width, height);
				data->EventCallback(event);
			});
		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
			{
				Data* data = static_cast<Data*>(glfwGetWindowUserPointer(window));

				WindowCloseEvent event;
				data->EventCallback(event);
			});
	}

	void Window::ClearCallbacks()
	{
		glfwSetKeyCallback(m_window, NULL);

		glfwSetMouseButtonCallback(m_window, NULL);
		glfwSetCursorPosCallback(m_window, NULL);
		glfwSetScrollCallback(m_window, NULL);

		glfwSetWindowSizeCallback(m_window, NULL);
		glfwSetWindowCloseCallback(m_window, NULL);
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