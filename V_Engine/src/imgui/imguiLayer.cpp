#include "pch.h"
#include "imguiLayer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

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

	void imguiLayer::StartDrawImGui()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void imguiLayer::EndDrawImGui()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup);
		}
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

	void imguiLayer::OnDrawImGui()
	{
		ImGui::ShowDemoWindow();
	}
}