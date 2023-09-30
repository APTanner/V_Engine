#include "pch.h"
#include "EventBuffer.h"

namespace V_Engine
{
	EventBuffer::EventBuffer()
	{
		
	}

	EventBuffer::~EventBuffer()
	{

	}

	void EventBuffer::Push(std::unique_ptr<Event> event)
	{
		m_buffer.push(std::move(event));
		++m_eventCount;
	}

	void EventBuffer::Pop()
	{
		m_buffer.pop();
		--m_eventCount;
	}

	Event& EventBuffer::front()
	{
		return *m_buffer.front();
	}
}
