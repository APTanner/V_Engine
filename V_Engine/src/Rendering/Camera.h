#pragma once

#include <glm/glm.hpp>
#include "Entity/Transform.h"
#include "Core/Events/WindowEvent.h"

namespace V_Engine 
{
	class Camera
	{
	public:
		Camera(float fieldOfView);
		~Camera();

		inline Transform& GetTransform() { return m_transform; }
		inline const glm::mat4& GetView() { UpdateViewMatrix();  return m_viewMatrix; }
		inline const glm::mat4& GetProjection() const { return m_projectionMatrix; }

		bool OnScreenResize(const WindowResizeEvent& event);
	private:
		void UpdateViewMatrix();
		void UpdateProjectionMatrix();
	private:
		Transform m_transform;
		glm::mat4 m_viewMatrix;
		glm::mat4 m_projectionMatrix;

		float m_fieldOfView;
	};
}

