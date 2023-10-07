#pragma once
#include "pch.h"

#include "Core/Events/Event.h"

namespace V_Engine
{
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer", bool enabled = true);
		virtual ~Layer();

		virtual void OnUpdate() {}
		virtual void OnDrawImGui() {}
		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_name; }
	protected:
		std::string m_name;
		bool m_enabled;
	};
}

