#pragma once
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
	private:
		static bool s_ImGuiInitialized;
	};
}

