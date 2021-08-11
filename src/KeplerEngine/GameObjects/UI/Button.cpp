#include "Button.h"
#include <KeplerEngine/Components/UI.h>

namespace KE
{
	void Button::Init()
	{
		AddComponent<Transform>(0.0f, 0.0f, 0.0f, 0.0f);
		AddComponent<RenderComponent>();
		AddComponent<UI>();
	}
}