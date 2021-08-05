#include "RenderComponent.h"
#include <KeplerEngine/RenderSystem/Texture.h>
#include <KeplerEngine/GameObjects/Base/GameObject.h>

namespace KE
{
	void RenderComponent::Init(const std::string& _File, unsigned int _Width, unsigned int _Height)
	{
		m_Texture = std::make_shared<Texture>(_File, 
			m_ParentObject.lock()->GetComponent<Transform>()->Position.x,
			m_ParentObject.lock()->GetComponent<Transform>()->Position.y,
			_Width, _Height);
	}

	void RenderComponent::OnBegin()
	{
		System::Draw(m_Texture);
	}

	void RenderComponent::OnUpdate()
	{
		System::Draw(m_Texture);
	}

	void RenderComponent::OnDisplay()
	{
	}
}