#include "SceneManager.h"

namespace KE
{
	std::shared_ptr<Scene> SceneManager::CreateScene()
	{
		std::string sceneName;
		if (m_Scenes.size() > 1)
			sceneName = "New Scene" + m_Scenes.size();
		else
			sceneName = "New Scene";

		std::shared_ptr<Scene> scene = std::make_shared<Scene>(sceneName);
		m_Scenes.push_back(scene);
	}

	std::shared_ptr<Scene> SceneManager::CreateScene(const std::string& _NewScene)
	{
		std::shared_ptr<Scene> scene = std::make_shared<Scene>(_NewScene);
		m_Scenes.push_back(scene);
	}
	
	void SceneManager::SetStartScene(std::shared_ptr<Scene>& _Scene)
	{
		m_CurrentScene = _Scene;
	}

	void SceneManager::UpdateScene(Time _T)
	{
		for (auto scene : m_Scenes)
		{
			scene->Tick(_T);
		}
	}

	void SceneManager::ChangeScene(const std::shared_ptr<Scene>& _Scene)
	{
		m_CurrentScene = _Scene;
	}
	
	const std::shared_ptr<Scene>& SceneManager::GetScene(const std::string& _SceneName)
	{
		for (auto scene : m_Scenes)
		{
			if (scene->GetSceneName() == _SceneName)
				return scene;
		}

		std::cout << "Scene " << _SceneName << " not found!\n";
		return nullptr;
	}

	SceneManager::~SceneManager()
	{
		m_CurrentScene = nullptr;
		m_Scenes.clear();
	}
}