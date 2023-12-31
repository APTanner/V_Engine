#include "pch.h"

#include "Input.h"

#include "Core/Application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace V_Engine
{
	bool Input::GetKeyDown(int keycode)
	{
		auto state = glfwGetKey(
			Application::Get().GetWindow().GetWindowPtr(),
			keycode
		);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::GetMouseButtonDown(int button)
	{
		auto state = glfwGetMouseButton(
			Application::Get().GetWindow().GetWindowPtr(),
			button
		);
		return state == GLFW_PRESS;
	}

	glm::vec2 Input::GetMousePosition()
	{
		double x;
		double y;
		glfwGetCursorPos(
			Application::Get().GetWindow().GetWindowPtr(),
			&x, &y
		);
		return glm::vec2((float)x, (float)y);
	}
}