#include "Event.h"

namespace KE
{
	bool Event::EventType(int _Event)
	{
		if (m_Event->type == _Event)
			return true;
		else
			return false;
	}
}