#pragma once
#include "Rendering/Shader.h"

namespace V_Engine
{
	constexpr static const char* shaderFileLocation = "..\\resources\\shaders";

	//TODO - turn this into a general ResourceLoader static class
	class ShaderLoader
	{
	public:
		static std::unique_ptr<Shader> LoadShaderFromFile(const std::string& shaderName);
	private:
		
	};
}

