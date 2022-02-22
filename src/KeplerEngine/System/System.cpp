#include "System.h"
#include <SDL.h>
#include <KeplerEngine/GameObjects/UI/Button.h>
#include <KeplerEngine/RenderSystem/Renderer.h>
#include <KeplerEngine/Scene/SceneManager.h>
#include <KeplerEngine/Components/Transform.h>
#include <KeplerEngine/Components/RenderComponent.h>

namespace KE
{
	void System::OnStart()
	{
		m_SceneManager->Start();
	}

	void System::MoveObject(std::shared_ptr<GameObject>& _Object, float _X, float _Y)
	{
		_Object->GetComponent<Transform>()->Position.x = _X;
		_Object->GetComponent<Transform>()->Position.y = _Y;
	}

	void System::MoveObject(std::shared_ptr<GameObject>& _Object, glm::vec2 _NewPosition)
	{
		_Object->GetComponent<Transform>()->Position = _NewPosition;
	}

	void System::Draw(std::shared_ptr<Texture>& _Texture)
	{
		Renderer::Submit(_Texture);
	}

	void System::ChangeScene(std::shared_ptr<Scene>& _Scene)
	{
		m_SceneManager->ChangeScene(_Scene);
	}

	//Buttons
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
		if (UIButtonEnter(_Button) && m_Event->type == SDL_MOUSEBUTTONDOWN)
			return true;
		else
			return false;
	}

	bool System::UIButtonReleased(std::shared_ptr<Button>& _Button)
	{
		if (UIButtonEnter(_Button) && m_Event->type == SDL_MOUSEBUTTONUP)
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
