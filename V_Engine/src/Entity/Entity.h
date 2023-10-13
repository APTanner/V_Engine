#pragma once

#include <glm/glm.hpp>

#include "Rendering/Mesh.h"
#include "Transform.h"

namespace V_Engine
{
	class Entity
	{
	public:
		Entity();
		~Entity();

		inline void SetMesh(std::shared_ptr<Mesh> mesh) { m_mesh = mesh; }

		inline Transform& GetTransform() { return m_transform; }
		inline Mesh& GetMesh() { return *m_mesh; }
	private:
		Transform m_transform;
		std::shared_ptr<Mesh> m_mesh;
	};
}

