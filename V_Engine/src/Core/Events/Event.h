#pragma once

#include "pch.h"
#include "Core/Core.h"
#include "Core/Log.h"

namespace V_Engine
{
	enum class EventType
	{
		None = 0,
		Event, // used when we just want to handle an arbitrary event 
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

// maybe used in the future if events have more complex member data
#define EVENT_MOVE_SEMANTICS(className, moveLogic) \
	className(className&& other) noexcept				\
		: Event(std::move(other))						\
	{													\
		moveLogic;										\
	}													\
	className& operator=(className&& other) noexcept	\
	{													\
		if (this != &other)								\
		{												\
			Event::operator=(std::move(other));			\
			moveLogic;									\
		}												\
	}
														

	class Event
	{
		friend class EventDispatcher;
	public:
		static EventType GetClassEventType() { return EventType::Event; }
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategory() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategory() & category;
		}

		inline bool IsHandled() const { return m_handled; }

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
			if (T::GetClassEventType() == EventType::Event || 
				m_event.GetEventType() == T::GetClassEventType())
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