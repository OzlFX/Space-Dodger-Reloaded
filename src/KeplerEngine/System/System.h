#pragma once

#include <KeplerEngine/GameObjects/UI/Button.h>
#include <KeplerEngine/RenderSystem/Renderer.h>
#include <KeplerEngine/Scene/SceneManager.h>
#include <KeplerEngine/Components/Transform.h>
#include <KeplerEngine/Components/RenderComponent.h>
#include <KeplerEngine/RenderSystem/Texture.h>
#include <unordered_map>

namespace KE
{
	class System
	{
	public:
		
		static void MoveObject(std::shared_ptr<GameObject>& _Object);
		static void AddScene(std::shared_ptr<Scene>& _Scene);
		static void ChangeScene(std::shared_ptr<Scene>& _Scene);

		//Buttons
		static bool UIButtonEnter(std::shared_ptr<Button>& _Button);
		static bool UIButtonPressed(std::shared_ptr<Button>& _Button);

	private:

		static void Init();
		static void Shutdown();

		static SDL_Rect& CacheBounds(std::shared_ptr<Button>& _Button);

		static std::unordered_map<std::shared_ptr<Button>&, SDL_Rect&> m_BoundCache;
		static int m_MousePosX, m_MousePosY;

		friend class Application;
	};
}