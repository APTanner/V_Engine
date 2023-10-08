#pragma once
#include <glad/glad.h>

#include <initializer_list>
#include "Core/Core.h"

namespace V_Engine
{
	struct BufferDataTypeData
	{
		int ComponentCount;
		int ElementSize;
		GLenum GLType;
	};

	static constexpr uint32_t numBufferDataTypes = 3;

	constexpr BufferDataTypeData bufferDataTypeData[numBufferDataTypes] = {
		{2, sizeof(float), GL_FLOAT},
		{3, sizeof(float), GL_FLOAT},
		{4, sizeof(float), GL_FLOAT},
	};

	enum class BufferDataType : uint32_t
	{
		Vector2 = 0, Vector3, Vector4,
	};

	enum class BufferDataNormalizationState
	{
		NotNormalized,
		Normalized
	};

	static bool checkDataArrayBounds(BufferDataType t)
	{
		int i = (uint32_t)t;
		if (i >= 0 && i < numBufferDataTypes)
		{
			return true;
		}
		throw std::out_of_range("No data for that BufferDataType");
		return false;
	}

	inline int GetBufferDataTypeComponentCount(BufferDataType t)
	{
		if (checkDataArrayBounds(t))
		{
			return bufferDataTypeData[(uint32_t)t].ComponentCount;
		}
		return 0;
	}

	inline int GetBufferDataTypeElementSize(BufferDataType t)
	{
		if (checkDataArrayBounds(t))
		{
			return bufferDataTypeData[(uint32_t)t].ElementSize;
		}
		return 0;
	}

	inline GLenum GetBufferDataTypeGLenum(BufferDataType t)
	{
		if (checkDataArrayBounds(t))
		{
			return bufferDataTypeData[(uint32_t)t].GLType;
		}
		return 0;
	}

	inline int GetBufferDataTypeSize(BufferDataType t)
	{
		return GetBufferDataTypeComponentCount(t) * GetBufferDataTypeElementSize(t);
	}

	struct VertexBufferElement
	{
		BufferDataType Type;
		int Offset;
		int Size;
		bool Normalized;

		std::string Name;

		VertexBufferElement(
			BufferDataType type,
			const std::string& name,
			BufferDataNormalizationState normalized = BufferDataNormalizationState::NotNormalized)
			:
			Type(type),
			Name(name),
			Normalized(normalized == BufferDataNormalizationState::Normalized ? true : false),
			Size(GetBufferDataTypeSize(type)),
			Offset(0)
		{
		}
	};

	class BufferLayout
	{
	public:
		BufferLayout() {}
		BufferLayout(std::initializer_list<VertexBufferElement> elems)
			: m_elements(elems)
		{
			CalculateStrideAndElementOffsets();
		}

		inline const std::vector<VertexBufferElement>& GetElements() const { return m_elements; }

		inline int GetStride() const { return m_stride; }
	private:
		void CalculateStrideAndElementOffsets();
	private:
		std::vector<VertexBufferElement> m_elements;
		int m_stride = 0;
	};

	class VertexBuffer
	{
	public:
		VertexBuffer(float* verticies, unsigned int size, BufferLayout layout);
		~VertexBuffer();

		void Bind() const;
		void Unbind() const;

		inline BufferLayout& GetLayout() { return m_layout; }
	private:
		unsigned int m_vbo = 0;
		BufferLayout m_layout;
	};

	class ElementBuffer
	{
	public:
		ElementBuffer(uint32_t* indicies, unsigned int size);
		~ElementBuffer();

		void Bind() const;
		void Unbind() const;
	private:
		unsigned int m_ebo = 0;
	};
}

