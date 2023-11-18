#include "pch.h"
#include "CameraController.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Core/Input.h"
#include "Rendering/Camera.h"

#include "Core/Application.h"
#include "Core/Time.h"

namespace V_Engine
{
	constexpr float viewSpeed = 1.0f;
	constexpr float moveSpeed = 1.0f;

	void CameraController::OnUpdate()
	{
		Camera& camera = Application::Get().GetCamera();
		if (Input::GetKeyDown(GLFW_KEY_W))
		{
			camera.GetTransform().TranslateLocalSpace(
				glm::vec3(0, 0, -1) * moveSpeed * Time::DeltaTime()
			);
		}
		if (Input::GetKeyDown(GLFW_KEY_S))
		{
			camera.GetTransform().TranslateLocalSpace(
				glm::vec3(0, 0, 1) * moveSpeed * Time::DeltaTime()
			);
		}
		if (Input::GetKeyDown(GLFW_KEY_A))
		{
			camera.GetTransform().TranslateLocalSpace(
				glm::vec3(-1, 0, 0) * moveSpeed * Time::DeltaTime()
			);
		}
		if (Input::GetKeyDown(GLFW_KEY_D))
		{
			camera.GetTransform().TranslateLocalSpace(
				glm::vec3(1, 0, 0) * moveSpeed * Time::DeltaTime()
			);
		}

		glm::vec2 currentMousePos = Input::GetMousePosition();
		if (Input::GetMouseButtonDown(GLFW_MOUSE_BUTTON_1))
		{
			glm::vec2 diff = currentMousePos - m_lastMousePosition;
			diff *= viewSpeed * Time::DeltaTime();
			m_yawAndPitch += diff;
			if (m_yawAndPitch.y > 89.0f)
			{
				m_yawAndPitch.y = 89.0f;
			}
			if (m_yawAndPitch.y < -89.0f)
			{
				m_yawAndPitch.y = -89.0f;
			}
			camera.GetTransform().SetRotation(glm::vec3(m_yawAndPitch.y, m_yawAndPitch.x, 0.0f));
		}
		m_lastMousePosition = currentMousePos;
	}

	
}
