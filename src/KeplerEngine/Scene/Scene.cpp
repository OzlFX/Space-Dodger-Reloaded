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

	const std::shared_ptr<GameObject>& Scene::GetEntity(const std::string& _EntityName) const
	{
		m_Entities.find(_EntityName);
	}

	void Scene::RemoveEntity(const std::string& _EntityName)
	{
		m_Entities.erase(_EntityName);
	}

	Scene::~Scene()
	{
		m_Entities.clear();
	}
}