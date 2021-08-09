#pragma once

#include <KeplerEngine/RenderSystem/Renderer.h>
#include <KeplerEngine/Components/Transform.h>
#include <KeplerEngine/Components/RenderComponent.h>

namespace KE
{
	class System
	{
	public:
		
		static void MoveObject(std::shared_ptr<GameObject>& _Object);
		static void Draw(std::shared_ptr<Texture>& _Texture);

	private:

		

	};
}