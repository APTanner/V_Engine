#include "pch.h"
#include "RenderOperations.h"

namespace V_Engine
{
	void RenderOperations::DrawInstanced(VertexArray& vertexArray)
	{
		vertexArray.Bind();
		glDrawElements(GL_TRIANGLES, vertexArray.GetIndexCount(), GL_UNSIGNED_INT, 0);
	}
}
