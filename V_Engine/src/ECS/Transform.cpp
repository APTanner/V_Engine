#include "pch.h"
#include "Transform.h"

#include <glm/gtc/matrix_transform.hpp>

static glm::mat4 rotateX(float radians)
{
	const float cos = glm::cos(radians);
	const float sin = glm::sin(radians);

	glm::mat4 matrix = glm::mat4(1.0f);
	matrix[1][1] = cos;
	matrix[1][2] = sin;
	matrix[2][1] = -sin;
	matrix[2][2] = cos;
	return matrix;
}

static glm::mat4 rotateY(float radians)
{
	const float cos = glm::cos(radians);
	const float sin = glm::sin(radians);

	glm::mat4 matrix = glm::mat4(1.0f);
	matrix[0][0] = cos;
	matrix[2][0] = sin;
	matrix[0][2] = -sin;
	matrix[2][2] = cos;
	return matrix;
}

static glm::mat4 rotateZ(float radians)
{
	const float cos = glm::cos(radians);
	const float sin = glm::sin(radians);

	glm::mat4 matrix = glm::mat4(1.0f);
	matrix[0][0] = cos;
	matrix[1][0] = -sin;
	matrix[0][1] = sin;
	matrix[1][1] = cos;
	return matrix;
}

static glm::mat4 getRotation(const glm::vec3& rotation)
{
	return rotateY(glm::radians(rotation.y)) *
		rotateX(glm::radians(rotation.x)) *
		rotateZ(glm::radians(rotation.z));
}

namespace V_Engine
{
	Transform::Transform()
	{
		m_localtoWorld = glm::mat4x4(1.0f);
		SetForwardandUp();
	}
	Transform::~Transform()
	{

	}

	void Transform::SetPosition(const glm::vec3& position)
	{
		m_localtoWorld[3] = glm::vec4(position, 1.0f);
	}
	void Transform::TranslateLocalSpace(const glm::vec3& v)
	{
		m_localtoWorld = glm::translate(m_localtoWorld, v);
	}
	void Transform::SetRotation(const glm::vec3& rotation)
	{
		m_localtoWorld = glm::translate(glm::mat4(1.0f), GetPosition()) * getRotation(rotation);
	}
	void Transform::Rotate(const glm::vec3& v)
	{
		m_localtoWorld = m_localtoWorld * getRotation(v);
		SetForwardandUp();
	}
	void Transform::SetForwardandUp()
	{
		m_forward = -glm::vec3(m_localtoWorld[2]); 
		m_up =  glm::vec3(m_localtoWorld[1]); 
	}
}