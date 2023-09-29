#pragma once

#include "pch.h"

#include "GLFW/glfw3.h"
#include "Core/Events/Event.h"



namespace V_Engine
{
	class GLFWManager;

	class Window
	{
	public:
		friend class GLFWManager;

		using f_EventCallback = std::function<void(Event&)>;

		struct Data
		{
			std::string Title;
			int Width;
			int Height;
			bool VSync;

			f_EventCallback EventCallback;

			Data(const std::string& title = "V",
				int width = 1920,
				int height = 1080,
				bool vSync = true)
				: Title(title), Width(width), Height(height), VSync(vSync)
			{
			}
		};

		~Window();

		void SetCallbacks();
		void ClearCallbacks();

		void OnUpdate();


		inline int GetWidth() const { return m_data.Width; }
		inline int GetHeight() const { return m_data.Height; }

		void SetVSync(bool enabled);
		bool IsVSync() const;

		inline void SetEventCallback(const f_EventCallback& callback) { m_data.EventCallback = callback; }
	private:
		Window(Data data);
		GLFWwindow* m_window;
		Data m_data;
		static bool s_GLFWInitialized;
	};
}


