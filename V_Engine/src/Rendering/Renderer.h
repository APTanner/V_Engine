#pragma once

#include "Physicals/Mesh.h"
namespace V_Engine
{
	class Renderer
	{
	public:
		static void BeginScene(/*scene, lights, camera*/);
		static void EndScene();

		static void SubmitMesh(Mesh& mesh);
	private:
		static bool m_rendering;
	};
}

