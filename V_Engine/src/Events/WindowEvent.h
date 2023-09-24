#pragma once

#include "Events/Event.h"

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
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_width(width), m_height(height) {}

		inline unsigned int GetWidth() const { return m_width; }
		inline unsigned int GetHeight() const { return m_height; }

		std::string ToString() const override
		{
			std::ostringstream oss;
			oss << "EVENT::WINDOW_RESIZE: " << m_width  << ", " << m_height;
			return oss.str();
		}

		EVENT_TYPE_FUNCTIONS(WindowResize)
		EVENT_CATEGRORY_FUNCTIONS(WindowCategoryEvent)
	private:
		unsigned int m_width;
		unsigned int m_height;
	};

}