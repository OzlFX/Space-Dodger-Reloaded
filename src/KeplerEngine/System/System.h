#pragma once
/* Deprecated Code */
#include <unordered_map>
#include <glm/vec2.hpp>
#include <memory>

#include <KeplerEngine/Scene/SceneManager.h>
#include <KeplerEngine/Core/LayerManager.h>

struct SDL_Rect;
union SDL_Event;
class GameObject;
class Texture;
class Scene;
class Button;

namespace KE
{
	/// <summary>
	/// Scrap the system, it is too complex for such a small project. Files will be left on github as a reminder and showcase of what
	/// has been done thus far, as well as to show that I believe that my implementation is terrible.
	/// </summary>
	class System
	{
	public:
		
		//Start Functions
		static void OnStart();

		//Run Functions
		static void MoveObject(std::shared_ptr<GameObject>& _Object, float _X, float _Y);
		static void MoveObject(std::shared_ptr<GameObject>& _Object, glm::vec2 _NewPosition);
		static void Draw(std::shared_ptr<Texture>& _Texture);
		static void ChangeScene(std::shared_ptr<Scene>& _Scene);

		//Buttons
		static bool UIButtonEnter(std::shared_ptr<Button>& _Button);
		static bool UIButtonPressed(std::shared_ptr<Button>& _Button);
		static bool UIButtonReleased(std::shared_ptr<Button>& _Button);

	private:

		static SDL_Rect& CacheBounds(std::shared_ptr<Button>& _Button);

		static std::unordered_map<std::shared_ptr<Button>&, SDL_Rect&> m_BoundCache;
		static int m_MousePosX, m_MousePosY;
		static SDL_Event* m_Event;

		static std::unique_ptr<LayerManager> m_LayerManager; //Instance of the layer manager
		static std::unique_ptr<SceneManager> m_SceneManager; //Instance of the scene manager

		friend class Application;
	};
}