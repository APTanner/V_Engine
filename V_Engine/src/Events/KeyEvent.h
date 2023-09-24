#pragma once

#include <sstream>

#include "Events/Event.h"

namespace V_Engine
{
	class KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_keyCode; }

		EVENT_CATEGRORY_FUNCTIONS(InputCategoryEvent | KeyboardCategoryEvent)
	protected:
		KeyEvent(int keyCode)
			: m_keyCode(keyCode) {}

		int m_keyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, int repeatCount)
			: KeyEvent(keyCode), m_repeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_repeatCount; }

		std::string ToString() const override
		{
			std::ostringstream oss;
			oss << "EVENT::KEY_PRESSED: " << m_keyCode << " (Repeated " << m_repeatCount << " times)";
		}

		EVENT_TYPE_FUNCTIONS(KeyPress)
	private:
		int m_repeatCount;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode) 
			: KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::ostringstream oss;
			oss << "EVENT::KEY_RELEASED: " << m_keyCode;
			return oss.str();
		}

		EVENT_TYPE_FUNCTIONS(KeyRelease)
	};

}
