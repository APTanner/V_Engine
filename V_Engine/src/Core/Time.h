#pragma once

namespace V_Engine
{
	class Time
	{
	public:
		static void Update();
		inline static float DeltaTime() { return m_deltaTime; }
	private:
		static float m_deltaTime;

		static float m_lastFrameTime;
	};
}

