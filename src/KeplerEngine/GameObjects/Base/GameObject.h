#pragma once

#include <memory>
#include <iostream>
#include <list>

#include <KeplerEngine/Components/Transform.h>

namespace KE
{
	class Component;

	class GameObject
	{
	public:

		GameObject() {}

		template <typename T, typename... Args>
		std::shared_ptr<T> AddComponent(Args&&... _Args)
		{
			if (!HasComponent<T>)
			{
				std::shared_ptr<T> component = std::make_shared<T>();

				if (component)
				{
					component->m_ParentObject = m_Self;
					component->m_Begin = false;
					component->OnInit(_Args...);
					m_Components.push_back(component);
					return component;
				}
				else
				{
					std::cout << "Error adding component!\n";
					return nullptr;
				}
			}
		}

		template <typename T>
		void RemoveComponent()
		{
			if (HasComponent<T>)
				m_Components.remove(T);
		}

		template <typename T>
		std::shared_ptr<T> GetComponent()
		{
			if (HasComponent<T>)
			{
				return std::make_shared<T>();
			}
			else
			{
				std::cout << "Component not in Component list of the Object\n";
				return nullptr;
			}
		}

		template <typename T>
		bool HasComponent()
		{
			for(auto components = m_Components.begin();
				components != m_Components.end();
				components++)
			{
				std::shared_ptr<T> component = std::dynamic_pointer_cast<T>(*components);

				if (component)
					return true;
				else
					return false;
			}
		}

		const std::string& GetName() { return m_Name; }

		virtual ~GameObject() = default;

	protected:

		virtual void Init();
		virtual void OnUpdate();

	private:

		std::weak_ptr<GameObject> m_Self;
		std::list<std::shared_ptr<Component>> m_Components;
		std::string m_Name;

		friend class Component;
		friend class Scene;

	};
}