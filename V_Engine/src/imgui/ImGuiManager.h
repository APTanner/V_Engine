#pragma once
#define IMGUI_ENABLE_DOCKING
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

namespace V_Engine 
{
	class ImGuiManager
	{
	public:
		ImGuiManager() = delete;
		ImGuiManager(const ImGuiManager&) = delete;
		ImGuiManager(ImGuiManager&&) = delete;

		static void Initialize();
		static void Shutdown();

		static inline bool WantCaptureMouse() { return ImGui::GetIO().WantCaptureMouse; }
		static inline bool WantCaptureKeyboard() { return ImGui::GetIO().WantCaptureKeyboard; }

	private:
		static bool s_ImGuiInitialized;
	};
}

