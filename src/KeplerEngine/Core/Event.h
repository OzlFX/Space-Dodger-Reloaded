#pragma once

#include <SDL.h>

namespace KE
{
	class Event
	{
	public:

		static bool EventType(int _Event);

		~Event() {}

	private:
		Event() {}

		static SDL_Event* m_Event;

		friend class Application;
	};
}