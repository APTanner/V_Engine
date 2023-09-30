#pragma once
#include <queue>

#include "Core/Events/Event.h"

namespace V_Engine
{
	class EventBuffer
	{
	public:
		EventBuffer();
		~EventBuffer();

		EventBuffer(const EventBuffer&) = delete;
		EventBuffer& operator=(const EventBuffer&) = delete;

		EventBuffer(EventBuffer&&) = delete;
		EventBuffer& operator=(EventBuffer&&) = delete;

		void Push(std::unique_ptr<Event> event);
		void Pop();

		Event& front();

		inline bool empty() const { return m_eventCount == 0; }
	private:
		int m_eventCount = 0;
		std::queue<std::unique_ptr<Event>> m_buffer;
	};
}

