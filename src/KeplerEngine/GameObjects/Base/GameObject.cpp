#include "GameObject.h"
#include "KeplerEngine/Components/Base/Components.h"

namespace KE
{
	void GameObject::Init()
	{
		AddComponent<Transform>()->Init(0.0f, 0.0f, 0.0f, 0.0f);
	}

	void GameObject::OnUpdate()
	{
		for (auto components = m_Components.begin();
			components != m_Components.end();
			components++)
		{
			if (!(*components)->m_Begin)
			{
				(*components)->OnBegin(); //Run beginning function
				(*components)->m_Begin = true; //It has begun!
			}

			(*components)->OnUpdate(); //Update components
		}
	}
}