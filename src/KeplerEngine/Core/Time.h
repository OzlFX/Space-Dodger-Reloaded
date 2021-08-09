#pragma once

namespace KE
{
	class Time
	{
	public:

		Time(float _Time = 0.0f)
			: m_Time(_Time)
		{
		}

		float GetSeconds() const { return m_Time; }
		float GetMilliseconds() const { return m_Time * 1000.0f; }

	private:

		float m_Time;

	};
}