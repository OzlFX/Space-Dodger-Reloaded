#pragma once

#include <unordered_map>
#include <KeplerEngine/GameObjects/Base/GameObject.h>

namespace KE
{
	class Scene
	{
	public:

		Scene();
		Scene(const std::string _SceneName);

		template <typename T>
		void AddEntity(const std::string& _EntityName, std::shared_ptr<T>& _Entity)
		{
			m_Entities.emplace(_EntityName, _Entity);
		}

		const std::shared_ptr<GameObject>& GetEntity(const std::string& _EntityName) const;
		
		void RemoveEntity(const std::string& _EntityName);

		~Scene();

	private:

		const std::string m_SceneName;
		std::unordered_map<std::string, std::shared_ptr<GameObject>> m_Entities;
		std::weak_ptr<Scene> m_Self;

	};
}