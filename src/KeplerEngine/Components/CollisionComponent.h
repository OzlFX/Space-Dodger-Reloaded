#pragma once

#include <KeplerEngine/Components/Base/Components.h>

struct SDL_Rect;

namespace KE
{
	class CollisionComponent : public Component
	{
	public:

		void SetCollisionBox(int _X, int _Y, int _Width, int _Height);
		void SetCollisionBox(SDL_Rect _Bounds);

		bool HasCollided(GameObject* _ObjectCollision);
		bool CheckCollision(GameObject* _ObjectCollision);

		GameObject& CheckForCollision();

		const SDL_Rect& GetCollisionBox() const { return m_CollisionBox; }

	private:

		void Init();
		void OnBegin();
		void OnUpdate() override;
		void OnDisplay();

		const SDL_Rect& m_CollisionBox;

	};
}
