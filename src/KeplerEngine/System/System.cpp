#include "System.h"

namespace KE
{
	void System::MoveObject(std::shared_ptr<GameObject>& _Object)
	{

	}

	void System::Draw(std::shared_ptr<Texture>& _Texture)
	{
		Renderer::Submit(_Texture);
	}

	void System::ChangeScene(std::shared_ptr<Scene>& _Scene)
	{
		SceneManager::ChangeScene();
	}

	//Buttons
	/** TODO: OnHover, OnPressed and OnReleased functionality may not need to be divided up **/
	bool System::UIButtonEnter(std::shared_ptr<Button>& _Button)
	{
		SDL_Rect Bounds = CacheBounds(_Button);

		//Check mouse pos if within dimensions of the object
		SDL_GetMouseState(&m_MousePosX, &m_MousePosY);

		if (((float)m_MousePosX > Bounds.x) &&
			((float)m_MousePosY > Bounds.h) &&
			((float)m_MousePosX < Bounds.w) &&
			((float)m_MousePosY < Bounds.y))
		{
			return true;
		}

		return false;
	}

	bool System::UIButtonPressed(std::shared_ptr<Button>& _Button)
	{
		/// TODO: Check left mouse button pressed
		if (UIButtonEnter(_Button))
			return true;
		else
			return false;
	}

	SDL_Rect& System::CacheBounds(std::shared_ptr<Button>& _Button)
	{
		if (m_BoundCache.find(_Button) != m_BoundCache.end())
		{
			return m_BoundCache[_Button];
		}
		else
		{
			m_BoundCache.emplace(_Button, _Button->GetComponent<RenderComponent>()->GetTexture()->GetData());
			return m_BoundCache[_Button];
		}
	}
}
