#pragma once

#include <list>
#include <string>

class GameObject;
class Button;
class Time;

namespace KE
{
	class Scene
	{
	public:

		Scene(const std::string _SceneName);

		void CreateEntity(const std::string& _EntityName);

		void Tick(Time _T);

		const std::shared_ptr<GameObject>& GetEntity(std::shared_ptr<GameObject>& _Entity) const;
		const std::string& GetSceneName() const { return m_SceneName; }
		
		void DeleteEntity(std::shared_ptr<GameObject>& _Entity);

		~Scene();

	private:

		const std::string m_SceneName;
		std::list<std::shared_ptr<GameObject>> m_Entities;
		std::list<std::shared_ptr<Button>> m_Buttons;
		std::weak_ptr<Scene> m_Self;

	};
}