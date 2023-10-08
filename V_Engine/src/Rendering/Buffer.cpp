#include "pch.h"
#include "Buffer.h"

namespace V_Engine
{

	BufferLayout::BufferLayout(std::initializer_list<VertexBufferElement> elems)
	{
		m_elements = std::vector<VertexBufferElement>(elems);
		CalculateStrideAndElementOffsets();
	}
	void BufferLayout::CalculateStrideAndElementOffsets()
	{
		int strideSoFar{};
		for (int i = 0; i < m_elements.size(); ++i)
		{
			VertexBufferElement& elem = m_elements[i];
			elem.Offset = strideSoFar;
			strideSoFar += elem.Size;
		}
		m_stride = strideSoFar;
	}


	VertexBuffer::VertexBuffer(float* verticies, unsigned int size)
	{
		glGenBuffers(1, &m_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		glBufferData(GL_ARRAY_BUFFER, size, verticies, GL_STATIC_DRAW);
	}
	void VertexBuffer::Bind() const 
	{

	}
	void VertexBuffer::Unbind() const
	{

	}

	ElementBuffer::ElementBuffer(uint32_t* indicies, unsigned int size)
	{
		glGenBuffers(1, &m_ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indicies, GL_STATIC_DRAW);
	}

	void ElementBuffer::Bind() const
	{

	}
	void ElementBuffer::Unbind() const
	{

	}
}
