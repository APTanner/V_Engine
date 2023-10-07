#include "pch.h"
#include "ImGuiManager.h"

#include "Core/Application.h"

namespace V_Engine
{
	bool ImGuiManager::s_ImGuiInitialized = false;

	void ImGuiManager::Initialize()
	{
		if (s_ImGuiInitialized) { return; }

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

		Application& app = Application::Get();
		Window& window = app.GetWindow();

		// Setup Platform/Renderer backends
		ImGui_ImplGlfw_InitForOpenGL(window.GetWindowPtr(), true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
		ImGui_ImplOpenGL3_Init();
	}

	void ImGuiManager::Shutdown()
	{
		if (!s_ImGuiInitialized) { return; }

		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}
}