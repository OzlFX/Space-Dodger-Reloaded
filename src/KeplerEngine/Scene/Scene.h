#pragma once

#include <list>
#include <KeplerEngine/Core/Time.h>
#include <KeplerEngine/GameObjects/Base/GameObject.h>

namespace KE
{
	class Scene
	{
	public:

		Scene();
		Scene(const std::string _SceneName);

		void CreateEntity(const std::string& _EntityName = "GameObject");

		void OnUpdate(Time _T);

		const std::shared_ptr<GameObject>& GetEntity(std::shared_ptr<GameObject>& _Entity) const;
		
		void DeleteEntity(std::shared_ptr<GameObject>& _Entity);

		~Scene();

	private:

		const std::string m_SceneName;
		std::list<std::shared_ptr<GameObject>> m_Entities;
		std::weak_ptr<Scene> m_Self;

	};
}