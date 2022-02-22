#pragma once

#include <vector>
#include <memory>

#include <KeplerEngine/Core/Time.h>

#include "Scene.h"

namespace KE
{
	class SceneManager
	{
	public:

		void CreateScene();
		void CreateScene(const std::string& _NewScene);

		const std::shared_ptr<Scene>& GetCurrentScene() { return m_CurrentScene; }
		const std::shared_ptr<Scene>& GetScene(const std::string& _SceneName);

		~SceneManager();

	private:
		
		void Start();
		void SetStartScene(const std::shared_ptr<Scene>& _Scene);
		void UpdateScene(Time _T);

		void ChangeScene(const std::shared_ptr<Scene>& _Scene);

		///Maybe use hashmap for this
		std::vector<std::shared_ptr<Scene>> m_Scenes;
		
		std::shared_ptr<Scene>& m_StartScene;
		std::shared_ptr<Scene>& m_CurrentScene;
		std::shared_ptr<Scene>& m_NextScene;

		std::string CheckSceneConflicts(const std::string& _SceneName);

		bool m_IsSceneChanging = false;

		friend class System;
	};
}