#include "Button.h"
#include <KeplerEngine/Components/Transform.h>
#include <KeplerEngine/Components/RenderComponent.h>
#include <KeplerEngine/Components/UI.h>

namespace KE
{
	void Button::Init()
	{
		AddComponent<RenderComponent>();
		AddComponent<UI>();
	}
}