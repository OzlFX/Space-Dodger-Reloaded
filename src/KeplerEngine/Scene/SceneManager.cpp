#include "SceneManager.h"

namespace KE
{
	//Create a new Scene with a predefined, incrementing name
	void SceneManager::CreateScene()
	{
		std::string sceneName = CheckSceneConflicts("New Scene");

		m_Scenes.push_back(std::make_shared<Scene>(sceneName));
	}

	//Create a new Scene with a defined name
	void SceneManager::CreateScene(const std::string& _NewScene)
	{
		std::string sceneName = CheckSceneConflicts(_NewScene);

		m_Scenes.push_back(std::make_shared<Scene>(sceneName));
	}
	
	//Set the starting Scene
	void SceneManager::SetStartScene(std::shared_ptr<Scene>& _Scene)
	{
		m_CurrentScene = _Scene;
	}

	//Update all Scenes
	void SceneManager::UpdateScene(Time _T)
	{
		m_CurrentScene->Tick(_T);
	}

	//Change Current Scene to a new defined Scene
	void SceneManager::ChangeScene(const std::shared_ptr<Scene>& _Scene)
	{
		m_CurrentScene = _Scene;
	}
	
	//Get the scene based on its name, returns the first scene found or null if no scene is found
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

	std::string SceneManager::CheckSceneConflicts(const std::string& _SceneName)
	{
		int numNameConflicts = 0;
		int doesConflict = 0;

		for (auto scenes : m_Scenes)
		{
			if (scenes->GetSceneName() == _SceneName) //Get Scene name
			{
				std::cout << "WARNING: Scene Name confliction! Consider changing the name to prevent issues /n";
					numNameConflicts++;
				doesConflict = 1;
			}
		}

		if (doesConflict == 1)
			return _SceneName + std::to_string(numNameConflicts);
		else
			return _SceneName;
	}

	SceneManager::~SceneManager()
	{
		m_CurrentScene = nullptr;
		m_Scenes.clear();
	}
}