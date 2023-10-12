#pragma once

#include <glm/vec4.hpp>
#include <glad/glad.h>

#include "VertexArray.h"

namespace V_Engine
{
	class RenderOperations
	{
	public:
		inline static void SetClearColor(glm::vec4 color)
		{
			glClearColor(color.x, color.y, color.z, color.w);
		}

		inline static void ClearColorBuffer()
		{
			glClear(GL_COLOR_BUFFER_BIT);
		}

		inline static void ClearDepthBuffer()
		{
			glClear(GL_DEPTH_BUFFER_BIT);
		}

		static void DrawInstanced(VertexArray& vertexArray);
	};
}

