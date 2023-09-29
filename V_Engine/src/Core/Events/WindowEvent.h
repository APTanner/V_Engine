#pragma once

#include "Core/Events/Event.h"

namespace V_Engine
{
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_TYPE_FUNCTIONS(WindowClose)
		EVENT_CATEGRORY_FUNCTIONS(WindowCategoryEvent)
	};

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(int width, int height)
			: m_width(width), m_height(height) {}

		inline int GetWidth() const { return m_width; }
		inline int GetHeight() const { return m_height; }

		std::string ToString() const override
		{
			std::ostringstream oss;
			oss << "EVENT::WINDOW_RESIZE: " << m_width  << ", " << m_height;
			return oss.str();
		}

		EVENT_TYPE_FUNCTIONS(WindowResize)
		EVENT_CATEGRORY_FUNCTIONS(WindowCategoryEvent)
	private:
		int m_width;
		int m_height;
	};

}