#include "pch.h"
#include "Mesh.h"

namespace V_Engine
{
	Mesh::Mesh(VertexArray* vao)
	{
		m_vao.reset(vao);
	}
	Mesh::~Mesh()
	{

	}
}
