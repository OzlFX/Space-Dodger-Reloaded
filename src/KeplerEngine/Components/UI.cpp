#include "UI.h"
#include <KeplerEngine/GameObjects/Base/GameObject.h>
#include <KeplerEngine/Components/RenderComponent.h>
#include <KeplerEngine/Core/Event.h>

namespace KE
{
	UI::UI() 
		: m_MousePosX(0), m_MousePosY(0)
	{
		if (m_ParentObject.lock()->HasComponent<RenderComponent>())
		{
			m_UIBounds = &m_ParentObject.lock()->GetComponent<RenderComponent>()->GetTexture()->GetData();
		}
		else
		{
			std::cout << "ERROR: No Render Component on current Object. Cannot set bounds./n";
			m_ParentObject.lock()->RemoveComponent<UI>(); ///Potential issue ????
		}

		//if (m_ParentObject.lock()->HasComponent<PlayerController>() ||
		//	m_ParentObject.lock()->HasComponent<MovementController>())
		//{
		//	std::cout << "WARNING: Object the UI component is attached to contains a movement component!/nRemoving UI component!/n";
		//	m_ParentObject.lock()->RemoveComponent<UI>(); ///Potential issue ????
		//}
	}

	bool UI::OnUIElementEnter(std::shared_ptr<GameObject>& _Button)
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

	bool UI::OnButtonPressed()
	{
		if (OnUIElementEnter(m_ParentObject.lock()) && Event::EventType(SDL_MOUSEBUTTONDOWN))
			return true;
		else
			return false;
	}

	bool UI::OnButtonReleased()
	{
		if (OnUIElementEnter(m_ParentObject.lock()) && Event::EventType(SDL_MOUSEBUTTONUP))
			return true;
		else
			return false;
	}

	const SDL_Rect& UI::CacheBounds(std::shared_ptr<GameObject>& _Button)
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