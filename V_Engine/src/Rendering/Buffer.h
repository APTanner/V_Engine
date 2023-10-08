#pragma once
#include <glad/glad.h>

#include <initializer_list>
#include "Core/Core.h"

namespace V_Engine
{
	static constexpr uint32_t numBufferDataTypes = 3;

	enum class BufferDataType : uint32_t
	{
		Vector2 = 0, Vector3, Vector4,
	};

	static struct BufferDataTypeData
	{
		int ElementCount;
		int ElementSize;
		GLenum GLType;
	};

	static constexpr BufferDataTypeData bufferDataTypeData[numBufferDataTypes] = {
		{2, sizeof(float), GL_FLOAT},
		{3, sizeof(float), GL_FLOAT},
		{4, sizeof(float), GL_FLOAT},
	};

	static int GetBufferDataTypeElementCount(BufferDataType t)
	{
		V_ASSERT((uint32_t)t < numBufferDataTypes, "You haven't added the static data for that BufferDataType yet");
		return bufferDataTypeData[(uint32_t)t].ElementCount;
	}

	static int GetBufferDataTypeElementSize(BufferDataType t)
	{
		V_ASSERT((uint32_t)t < numBufferDataTypes, "You haven't added the static data for that BufferDataType yet");
		return bufferDataTypeData[(uint32_t)t].ElementSize;
	}

	static GLenum GetBufferDataTypeGLenum(BufferDataType t)
	{
		V_ASSERT((uint32_t)t < numBufferDataTypes, "You haven't added the static data for that BufferDataType yet");
		return bufferDataTypeData[(uint32_t)t].GLType;
	}

	static int GetBufferDataTypeSize(BufferDataType t)
	{
		return GetBufferDataTypeElementCount(t) * GetBufferDataTypeElementSize(t);
	}

	struct VertexBufferElement
	{
		BufferDataType Type;
		int Offset;
		int Size;

		std::string Name;

		VertexBufferElement(BufferDataType type, const std::string& name)
			: Type(type), Name(name), Offset(0), Size(GetBufferDataTypeSize(type))
		{
		}
	};

	class BufferLayout
	{
	public:
		BufferLayout(std::initializer_list<VertexBufferElement> elems);

		inline const std::vector<VertexBufferElement>& GetElements() const { return m_elements; }

		inline int GetStride() const { return m_stride; }
	private:
		void CalculateStrideAndElementOffsets();
	private:
		std::vector<VertexBufferElement> m_elements;
		int m_stride;
	};

	class VertexBuffer
	{
	public:
		VertexBuffer(float* verticies, unsigned int size);

		void Bind() const;
		void Unbind() const;
	private:
		unsigned int m_vbo = 0;
	};

	class ElementBuffer
	{
	public:
		ElementBuffer(uint32_t* indicies, unsigned int size);

		void Bind() const;
		void Unbind() const;
	private:
		unsigned int m_ebo = 0;
	};
}

