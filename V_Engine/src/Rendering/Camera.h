#pragma once

#include "Entity/Transform.h"

namespace V_Engine 
{
	class Camera
	{
	public:
		inline Transform& GetTransform() { return m_transform; }
	private:
		Transform m_transform;
	};
}

