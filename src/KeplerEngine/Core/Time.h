#pragma once

namespace KE
{
	class Time
	{
	public:

		Time(float _Time = 0.0f)
			: m_CurrentTime(_Time), DeltaTime(m_DeltaTime)
		{

		}

		void StartOfFrame()
		{
			m_DeltaTime = (m_CurrentTime - m_LastFrameTime) / 1000;
			m_LastFrameTime = m_CurrentTime;
		}

		float GetSeconds() const { return m_CurrentTime / 1000; }
		float GetMilliseconds() const { return m_CurrentTime; }

		const float& DeltaTime;

	private:

		float m_DeltaTime = 0.0f;
		float m_LastFrameTime = 0.0f;
		float m_CurrentTime;

	};
}