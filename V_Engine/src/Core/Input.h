#pragma once

#include "pch.h"

#include <glm/glm.hpp>

namespace V_Engine
{
	class Input
	{
	public:
		static bool GetKeyDown(int keycode);
		static bool GetMouseButtonDown(int button);
		static glm::vec2 GetMousePosition();
	private:
	};
}