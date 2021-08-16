#include "SceneManager.h"

namespace KE
{
	void SceneManager::CreateScene()
	{
		std::string sceneName;
		if (m_Scenes.size() > 1)
			sceneName = "New Scene" + m_Scenes.size();
		else
			sceneName = "New Scene";

		std::shared_ptr<Scene> scene = std::make_shared<Scene>(sceneName);
		m_Scenes.push_back(scene);
	}

	void SceneManager::CreateScene(const std::string& _NewScene)
	{
		std::shared_ptr<Scene> scene = std::make_shared<Scene>(_NewScene);
		m_Scenes.push_back(scene);
	}
	
	void SceneManager::SetStartScene()
	{
		m_CurrentScene = m_Scenes.at(0);
	}

	void SceneManager::UpdateScene(Time _T)
	{
		m_CurrentScene->OnUpdate(_T);
	}

	void SceneManager::ChangeScene()
	{
	}

	void SceneManager::SetCurrentScene()
	{
	}
	
	SceneManager::~SceneManager()
	{
		m_CurrentScene = nullptr;
		m_Scenes.clear();
	}
}