#include "pch.h"
#include "Renderer.h"
#include "RenderOperations.h"

namespace V_Engine
{
	bool Renderer::m_rendering = false;

	void Renderer::BeginScene()
	{
		m_rendering = true;
	}
	void Renderer::EndScene()
	{
		m_rendering = false;
	}
	void Renderer::SubmitMesh(Mesh& mesh)
	{
		V_ASSERT(m_rendering, "Submitting a mesh outside of scene drawing");
		RenderOperations::DrawInstanced(mesh.GetVertexArray());
	}
}