#pragma once
#include "pch.h"

#include "Log.h"
#include "Core/GLFW/GLFWManager.h"
#include "Core/Events/WindowEvent.h"
#include "Core/LayerStack.h"
#include "Core/EventBuffer.h"

namespace V_Engine
{
	class Application
	{
	public:
		Application();
		~Application();

		void Run();

		void OnEvent(std::unique_ptr<Event> event);
		bool OnWindowClose(const WindowCloseEvent& event);
	private:
		std::unique_ptr<Window> m_window;
		LayerStack m_layerStack;
		EventBuffer m_eventBuffer;
		bool m_running = true;

		void HandleEvents();
	};
}