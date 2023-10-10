#pragma once
#include "Rendering/Shader.h"

namespace V_Engine
{
	constexpr static const char* shaderFileLocation = "..\\resources\\shaders";

	class ShaderLoader
	{
	public:
		static std::unique_ptr<Shader> LoadShaderFromFile(const std::string& shaderName);
	private:
		
	};
}

