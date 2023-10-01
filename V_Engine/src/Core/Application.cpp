#include "pch.h"
#include "Application.h"

#include "Events/WindowEvent.h"
#include "imgui/ImGuiManager.h"
#include "imgui/imguiLayer.h"



namespace V_Engine
{

	Application* Application::m_instance = nullptr;

	Application::Application()
	{
		V_ASSERT(m_instance == nullptr, "Can't have multiple applications");
		m_instance = this;

		// initialization
		Log::init();
		m_window = std::unique_ptr<Window>(GLFWManager::InstantiateWindow());
		m_window->SetEventCallback([this](std::unique_ptr<Event> e)
			{
				this->OnEvent(std::move(e));
			});

		m_layerStack.Push(new imguiLayer());
	}

	Application::~Application()
	{
		// delete the window to stop it trying to deallocate itself after GLFW has already
		//   been shut down
		m_window.reset();
		ImGuiManager::Shutdown();
		GLFWManager::Shutdown();
	}

	void Application::Run()
	{
		while (m_running)
		{
			glClearColor(.51, .45, .9, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_window->OnUpdate();
			HandleLayerUpdates();
			HandleEvents();
			m_window->OnSwapBuffers();
		}
	}

	void Application::OnEvent(std::unique_ptr<Event> event)
	{
		m_eventBuffer.Push(std::move(event));
	}

	bool Application::OnWindowClose(const WindowCloseEvent& event)
	{
		m_running = false;
		return true;
	}

	void Application::HandleEvents()
	{
		while (!m_eventBuffer.empty())
		{
			Event& e = m_eventBuffer.front();
			LOG_DEBUG(e.ToString());
			EventDispatcher d{ e };
			d.Dispatch<WindowCloseEvent>([this](const WindowCloseEvent& event) -> bool
				{
					return this->OnWindowClose(event);
				});
			m_eventBuffer.Pop();
		}
	}

	void Application::HandleLayerUpdates()
	{
		// update layers
		for (auto it = m_layerStack.layerBegin(); it != m_layerStack.layerEnd(); ++it)
		{
			(*it)->OnUpdate();
		}
		// update overlays
		for (auto it = m_layerStack.overlayBegin(); it != m_layerStack.overlayEnd(); ++it)
		{
			(*it)->OnUpdate();
		}
	}
}
