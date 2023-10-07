#pragma once
#include "pch.h"

#include "GLFW/glfw3.h"
#include "Log.h"
#include "GLFW/GLFWManager.h"
#include "Core/Events/WindowEvent.h"
#include "Core/LayerStack.h"
#include "Core/EventBuffer.h"
#include "imgui/imguiLayer.h"

namespace V_Engine
{
	class Application
	{
	public:
		Application();
		~Application();

		inline static Application& Get() { return *m_instance; };
		inline Window& GetWindow() const { return *m_window; }

		void Run();

		void OnEvent(std::unique_ptr<Event> event);
		bool OnWindowClose(const WindowCloseEvent& event);
	private:
		static Application* m_instance;

		std::unique_ptr<Window> m_window;
		imguiLayer* m_imguiLayer;
		LayerStack m_layerStack;
		EventBuffer m_eventBuffer;

		bool m_running = true;

		void HandleEvents();
		void HandleLayerUpdates();
	};
}