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

		static void CreateScene();
		static void CreateScene(const std::string& _NewScene);

		static const std::shared_ptr<Scene>& GetCurrentScene() { return m_CurrentScene; }

		~SceneManager();

	private:
		
		static void StartScene();
		static void UpdateScene(Time _T);

		static void ChangeScene();

		static void SetCurrentScene();

		///Maybe use hashmap for this
		static std::vector<std::shared_ptr<Scene>> m_Scenes;
		
		static std::shared_ptr<Scene>& m_CurrentScene;
		static std::shared_ptr<Scene>& m_NextScene;

		bool m_IsSceneChanging = false;

		friend class System;
	};
}