#pragma once

#include <glad/glad.h>

namespace V_Engine 
{
	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

		void Bind() const;
		void Unbind() const;
	private:
		GL_UNSIGNED_INT
	};
}

