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
		}
		// the memory class doesn't have access to Window's contructor
		//   therefore, we have to allocate the memory ourselves, then
		//   wrap it
		return std::unique_ptr<Window>(new Window(windowData));
	}

	void GLFWManager::Shutdown()
	{
		glfwTerminate();
	}
}