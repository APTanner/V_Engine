#pragma once
#include "Core/Layer.h"

namespace V_Engine
{
	class imguiLayer : public Layer
	{
	public:
		imguiLayer();
		~imguiLayer();

		void OnUpdate();
		
		void OnAttach();
		void OnDetach();

		void OnEvent(Event& event);
	private:
		float m_time = 0.0f;
	};
}

