#include "pch.h"

#include "Input.h"

#include "Core/Application.h"

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

	std::pair<float, float> Input::GetMousePosition()
	{
		double x;
		double y;
		glfwGetCursorPos(
			Application::Get().GetWindow().GetWindowPtr(),
			&x, &y
		);
		return std::pair<float,float>((float)x, (float)y);
	}
}