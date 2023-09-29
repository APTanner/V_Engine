#pragma once

#include "pch.h"
#include "Core/Core.h"

namespace V_Engine
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMove,
		KeyPress, KeyRelease,
		MouseButtonPress, MouseButtonRelease, MouseMove, MouseScroll
	};

	enum EventCategory
	{
		None = 0,
		WindowCategoryEvent      = BIT_LOC(0),
		InputCategoryEvent       = BIT_LOC(1),
		KeyboardCategoryEvent    = BIT_LOC(2),
		MouseCategoryEvent       = BIT_LOC(3),
		MouseButtonCategoryEvent = BIT_LOC(4)
	};

#define EVENT_TYPE_FUNCTIONS(type) static EventType GetClassEventType() { return EventType::type;}\
									virtual EventType GetEventType() const override { return GetClassEventType();}\
									virtual const char* GetName() const override { return STRINGIZE(EVENT::type);}

#define EVENT_CATEGRORY_FUNCTIONS(category) virtual int GetCategory() const override { return category; }

	class Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategory() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategory() & category;
		}
	protected:
		bool m_handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFunc = std::function<bool(const T&)>;
	public:
		EventDispatcher(Event& event) 
			: m_event(event) {}

		// T is any event type
		template<typename T>
		bool Dispatch(EventFunc<T> func)
		{
			if (m_event.GetEventType() == T::GetClassEventType())
			{
				m_event.m_handled = func(dynamic_cast<T&>(m_event));
				return true;
			}
			return false;
		}
	private:
		Event& m_event;
	};
}