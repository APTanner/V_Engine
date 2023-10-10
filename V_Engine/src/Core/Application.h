#pragma once
#include "pch.h"

#include "Core/Events/WindowEvent.h"
#include "Core/LayerStack.h"
#include "Core/EventBuffer.h"
#include "imgui/imguiLayer.h"
#include "Rendering/VertexArray.h"
#include "Rendering/Shader.h"

#include "GLFW/Window.h"


namespace V_Engine
{
	class Application
	{
	public:
		Application();
		~Application();

		inline static Application& Get() { return *m_instance; };
		inline Window& GetWindow() const { return *m_window; }

		void Update();

		void OnEvent(std::unique_ptr<Event> event);
		bool OnWindowClose(const WindowCloseEvent& event);
	private:
		void HandleEvents();
		void HandleLayerUpdates();
	private:
		static Application* m_instance;

		std::unique_ptr<Window> m_window;
		imguiLayer* m_imguiLayer;
		LayerStack m_layerStack;
		EventBuffer m_eventBuffer;

		std::unique_ptr<VertexArray> m_vertexArray;
		std::unique_ptr<Shader> m_shader;

		bool m_running = true;
	};
}