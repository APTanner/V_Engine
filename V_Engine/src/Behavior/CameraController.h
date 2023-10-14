#pragma once

#include <glm/glm.hpp>
#include "Core/Layer.h"
namespace V_Engine
{
	class CameraController : public Layer
	{
	public:
		void OnUpdate() override;
	private:
		glm::vec2 m_lastMousePosition = glm::vec2();
		glm::vec2 m_yawAndPitch = glm::vec2();
	};
}

