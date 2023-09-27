#pragma once

#include "pch.h"

#include "GLFW/glfw3.h"
#include "Core/Events/Event.h"

namespace V_Engine
{
	class Window
	{
	public:
		using f_EventCallback = std::function<void(Event&)>;

		struct Data
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool VSync;

			f_EventCallback EventCallback;

			Data(const std::string& title = "V",
				unsigned int width = 1920,
				unsigned int height = 1080,
				bool vSync = false)
				: Title(title), Width(width), Height(height), VSync(vSync)
			{
			}
		};

		Window(Data data);

		void OnUpdate();

		inline unsigned int GetWidth() const { return m_data.Width; }
		inline unsigned int GetHeight() const { return m_data.Height; }

		void SetVSync(bool enabled);
		bool IsVSync() const;

		inline void SetEventCallback(const f_EventCallback& callback) { m_data.EventCallback = callback; }
	private:
		GLFWwindow* m_window;
		Data m_data;
		static bool s_GLFWInitialized;
	};
}


