#include "pch.h"
#include "imguiLayer.h"

#include "GLFW/glfw3.h"

#include "Core/Application.h"
#include "imgui/ImGuiManager.h"

#include "Core/Events/Event.h"
#include "Core/Events/MouseEvent.h"
#include "Core/Events/KeyEvent.h"


namespace V_Engine
{

	imguiLayer::imguiLayer()
		: Layer("Debug")
	{
	}

	imguiLayer::~imguiLayer()
	{
	}

	void imguiLayer::OnAttach()
	{
		ImGuiManager::Initialize();
	}

	void imguiLayer::OnDetach()
	{
		//maybe shutdown?
		// currently handled by the application
	}

	void imguiLayer::OnUpdate()
	{
		ImGuiManager::Update();
	}

	void imguiLayer::OnEvent(Event& event)
	{
		EventDispatcher d{ event };
		
		if (event.IsInCategory(MouseCategoryEvent))
		{
			d.Dispatch<Event>([](const Event& event) -> bool
				{
					return ImGuiManager::WantCaptureMouse();
				});
		}
		else if (event.IsInCategory(KeyboardCategoryEvent))
		{
			d.Dispatch<Event>([](const Event& event) -> bool
				{
					return ImGuiManager::WantCaptureKeyboard();
				});
		}
	}
}