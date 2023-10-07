#pragma once
#include "Core/Layer.h"

namespace V_Engine
{
	class imguiLayer : public Layer
	{
	public:
		imguiLayer();
		~imguiLayer();

		void OnDrawImGui() override;
		
		void OnAttach() override;
		void OnDetach() override;

		void OnEvent(Event& event) override;

		void StartDrawImGui();
		void EndDrawImGui();
	private:
		float m_time = 0.0f;
	};
}

