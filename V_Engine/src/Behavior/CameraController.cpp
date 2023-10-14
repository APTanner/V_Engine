#include "pch.h"
#include "CameraController.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Core/Input.h"
#include "Rendering/Camera.h"

#include "Core/Application.h"
#include "Core/Time.h"

static void printVector(glm::vec3 v)
{
	std::cout << "(" << v.x << ',' << v.y << ',' << v.z << ")" << std::endl;
}

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
			std::cout << "Pitch: " << m_yawAndPitch.y << ", Yaw: " << m_yawAndPitch.x << std::endl;
			glm::vec3 heading = camera.GetTransform().GetForward();
			heading = glm::normalize(heading);

			// Calculate pitch (angle with the XZ plane)
			float pitchRadians = std::asin(heading.y);
			float pitchDegrees = glm::degrees(pitchRadians);
			std::cout << "Pitch from heading: " << pitchDegrees << std::endl;

			float yaw = std::atan2(heading.z, heading.x);
			float yawDegrees = glm::degrees(yaw);
			std::cout << "Yaw from heading: " << yawDegrees << std::endl;

		}
		m_lastMousePosition = currentMousePos;
	}

	
}
