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

		static std::shared_ptr<Scene> CreateScene();
		static std::shared_ptr<Scene> CreateScene(const std::string& _NewScene);

		static const std::shared_ptr<Scene>& GetCurrentScene() { return m_CurrentScene; }
		static const std::shared_ptr<Scene>& GetScene(const std::string& _SceneName);

		~SceneManager();

	private:
		
		static void SetStartScene(std::shared_ptr<Scene>& _Scene = m_Scenes.at(0));
		static void UpdateScene(Time _T);

		static void ChangeScene(const std::shared_ptr<Scene>& _Scene);

		///Maybe use hashmap for this
		static std::vector<std::shared_ptr<Scene>> m_Scenes;
		
		static std::shared_ptr<Scene>& m_CurrentScene;
		static std::shared_ptr<Scene>& m_NextScene;

		bool m_IsSceneChanging = false;

		friend class System;
	};
}