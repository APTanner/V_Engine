#include "pch.h"
#include "Time.h"

#include <GLFW/glfw3.h>

namespace V_Engine
{
	float Time::m_deltaTime = 0.0f;
	float Time::m_lastFrameTime = 0.0f;

	void Time::Update()
	{
		float currentTime = (float)glfwGetTime();
		m_deltaTime = currentTime - m_lastFrameTime;
		m_lastFrameTime = currentTime;
	}
}
