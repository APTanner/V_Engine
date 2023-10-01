#include "pch.h"
#include "imguiLayer.h"

#include "GLFW/glfw3.h"

#include "Core/Application.h"
#include "imgui/ImGuiManager.h"

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

	}

}