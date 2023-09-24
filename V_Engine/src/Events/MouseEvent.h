#pragma once

#include <sstream>

#include "Events/Event.h"

namespace V_Engine
{
	class MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_button; }

		EVENT_CATEGRORY_FUNCTIONS(MouseButtonCategoryEvent | MouseCategoryEvent | InputCategoryEvent )
	protected:
		MouseButtonEvent(int button)
			: m_button(button) {}
		int m_button;
	};

	class MouseButtonPressEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressEvent(int button)
			: MouseButtonEvent(button) {}
		
		std::string ToString() const override
		{
			std::ostringstream oss;
			oss << "EVENT::MOUSE_BUTTON_PRESS: " << m_button;
			return oss.str();
		}

		EVENT_TYPE_FUNCTIONS(MouseButtonPress)
	};

	class MouseButtonReleaseEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleaseEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::ostringstream oss;
			oss << "EVENT::MOUSE_BUTTON_RELEASE: " << m_button;
			return oss.str();
		}

		EVENT_TYPE_FUNCTIONS(MouseButtonRelease)
	};

	class MouseMoveEvent : public Event
	{
	public: 
		MouseMoveEvent(float x, float y)
			: m_mouseX(x), m_mouseY(y) {}

		inline float GetX() const { return m_mouseX; }
		inline float GeyY() const { return m_mouseY; }

		std::string ToString() const override
		{
			std::ostringstream oss;
			oss << "EVENT::MOUSE_MOVE: x:" << m_mouseX << " ,y:" << m_mouseY;
			return oss.str();
		}

		EVENT_TYPE_FUNCTIONS(MouseMove)
		EVENT_CATEGRORY_FUNCTIONS(MouseCategoryEvent | InputCategoryEvent)
	private:
		float m_mouseX;
		float m_mouseY;
	};

	class MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(float xOffset, float yOffset) 
			: m_xOffset(xOffset), m_yOffset(yOffset) {}

		inline float GetXOffset() const { return m_xOffset; }
		inline float GetYOffset() const { return m_yOffset; }

		EVENT_TYPE_FUNCTIONS(MouseScroll)
		EVENT_CATEGRORY_FUNCTIONS(MouseCategoryEvent | InputCategoryEvent)
	private:
		float m_xOffset;
		float m_yOffset;
	};
}