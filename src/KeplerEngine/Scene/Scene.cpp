#include "Scene.h"

namespace KE
{
	Scene::Scene()
		: m_SceneName("New Scene")
	{
	}

	Scene::Scene(const std::string _SceneName)
		: m_SceneName(_SceneName)
	{
	}

	void Scene::CreateEntity(const std::string& _EntityName)
	{
		std::shared_ptr<GameObject> entity = std::make_shared<GameObject>();
		entity->m_Name = _EntityName;

		m_Entities.push_back(entity);
	}

	void Scene::OnUpdate(Time _T)
	{
		for (auto entity : m_Entities)
		{
			entity->OnUpdate();
		}
	}

	const std::shared_ptr<GameObject>& Scene::GetEntity(std::shared_ptr<GameObject>& _Entity) const
	{
		for (auto& entity : m_Entities)
		{
			if (entity == _Entity)
				return entity;
		}

		std::cout << "Entity " << _Entity->GetName() << " cannot be found!\n";
		return nullptr;
	}

	void Scene::DeleteEntity(std::shared_ptr<GameObject>& _Entity)
	{
		m_Entities.remove(_Entity);
	}

	Scene::~Scene()
	{
		m_Entities.clear();
	}
}