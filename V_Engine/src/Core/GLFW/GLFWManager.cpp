#include "pch.h"
#include "GLFWManager.h"

namespace V_Engine
{
	bool GLFWManager::s_GLFWInitialized;

	std::unique_ptr<Window> GLFWManager::InstantiateWindow(const Window::Data& windowData)
	{
		if (!s_GLFWInitialized)
		{
			if (!glfwInit())
			{
				LOG_ERROR("GLFW not initialized");
			}
			s_GLFWInitialized = true;
			glfwSetErrorCallback(GLFWErrorCallback);
		}
		// the memory class doesn't have access to Window's contructor
		//   therefore, we have to allocate the memory ourselves, then
		//   wrap it
		auto ptr = std::unique_ptr<Window>(new Window(windowData));
		ptr->SetCallbacks();
		return ptr;
	}

	void GLFWManager::GLFWErrorCallback(int error, const char* message)
	{
		LOG_ERROR("GLFW Error [%i]: %s", error, message);
	}

	void GLFWManager::Shutdown()
	{
		glfwTerminate();
	}
}