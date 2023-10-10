#include "pch.h"
#include "ShaderLoader.h"

#include <filesystem>
#include <fstream>

#include "Core/Log.h"


namespace V_Engine 
{
	Shader* ShaderLoader::LoadShaderFromFile(const std::string& shaderName)
	{
		std::filesystem::path folderPath(shaderFileLocation);

		auto pathToFile = std::filesystem::absolute(folderPath / (shaderName + ".vert"));
		std::ifstream vShaderFile(pathToFile);
		if (!vShaderFile)
		{
			LOG_ERROR("Failed to open shader file: %s", pathToFile.string());
		}

		pathToFile = std::filesystem::absolute(folderPath / (shaderName + ".frag"));
		std::ifstream fShaderFile(pathToFile);
		if (!fShaderFile)
		{
			LOG_ERROR("Failed to open shader file: %s", pathToFile.string());
		}

		std::stringstream vShader;
		vShader << vShaderFile.rdbuf();

		std::stringstream fShader;
		fShader << fShaderFile.rdbuf();

		return new Shader(vShader.str(), fShader.str());
	}
}
