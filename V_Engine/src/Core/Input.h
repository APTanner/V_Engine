#pragma once

#include <GLFW/glfw3.h>
#include "pch.h"

namespace V_Engine
{
	class Input
	{
	public:
		inline static bool GetKeyDown(int keycode);
		inline static bool GetMouseButtonDown(int button);
		inline static std::pair<float, float> GetMousePosition();
	private:
	};
}