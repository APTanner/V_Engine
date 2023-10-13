#pragma once

#include "Rendering/VertexArray.h"
namespace V_Engine
{
	class Mesh
	{
	public:
		// eventually this will be used to make the contruction of vertex arrays simpler
		// for now, this is just a wrapper for the vertex array object
		Mesh(VertexArray* vao);
		~Mesh();

		inline void SetVertexArray(std::unique_ptr<VertexArray> vao) { m_vao = std::move(vao); }
		inline VertexArray& GetVertexArray() { return *m_vao; }
	private:
		std::unique_ptr<VertexArray> m_vao;
	};
}

