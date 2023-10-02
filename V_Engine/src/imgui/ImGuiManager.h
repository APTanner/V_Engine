#pragma once
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

		static void Update();

		static inline bool WantCaptureMouse() { return io->WantCaptureMouse; }
		static inline bool WantCaptureKeyboard() { return io->WantCaptureKeyboard; }

	private:
		static bool s_ImGuiInitialized;
		static ImGuiIO* io;
	};
}

