#include "pch.h"
#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

#include "Core/Application.h"

namespace V_Engine
{
    constexpr float aspectRatio = 1.5f;

    Camera::Camera(float fieldOfView)
    {
        m_viewMatrix = glm::mat4(1.0f);
        m_projectionMatrix = glm::mat4(1.0f);
        UpdateViewMatrix();
        m_fieldOfView = glm::radians(fieldOfView);
        UpdateProjectionMatrix();
    }
    Camera::~Camera()
    {
    }

    void Camera::UpdateViewMatrix()
    {
       m_viewMatrix = glm::lookAt(
            m_transform.GetPosition(),
            m_transform.GetForward() + m_transform.GetPosition(),
            m_transform.GetUp());
    }

    void Camera::UpdateProjectionMatrix()
    {
        m_projectionMatrix = glm::perspective(
            m_fieldOfView, 
            aspectRatio,
            0.1f, 100.0f);
    }

    bool Camera::OnScreenResize(const WindowResizeEvent& e)
    {
        LOG_DEBUG("Resizing");
        UpdateProjectionMatrix();
        return false;
    }
}
