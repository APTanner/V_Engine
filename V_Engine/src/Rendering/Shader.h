#pragma once
#include <string>

namespace V_Engine
{
	class Shader
	{
	public:
		Shader(const std::string& vertexSource, const std::string& fragSource);
		~Shader();

		void Bind() const;
		void Unbind() const;
	private:
		unsigned int m_shader = 0;
	};
}