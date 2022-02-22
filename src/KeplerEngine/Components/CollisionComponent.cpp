#include "CollisionComponent.h"
#include "KeplerEngine/GameObjects/Base/GameObject.h"

#include <SDL.h>

namespace KE
{
	void CollisionComponent::SetCollisionBox(int _X, int _Y, int _Width, int _Height)
	{

	}

	void CollisionComponent::SetCollisionBox(SDL_Rect _Bounds)
	{
	}

	//Basic Collision check, just returns TRUE or FALSE
	bool CollisionComponent::HasCollided(GameObject* _ObjectCollision)
	{
		return SDL_HasIntersection(&m_CollisionBox, &_ObjectCollision->GetComponent<CollisionComponent>()->GetCollisionBox());
	}

	//More advanced Collision check, checks the collider object for a collision component. Returns TRUE or FALSE
	bool CollisionComponent::CheckCollision(GameObject* _ObjectCollision)
	{
		if (_ObjectCollision->HasComponent<CollisionComponent>())
		{
			return HasCollided(_ObjectCollision);
		}
		else
		{
			std::cout << "No Collision Component Found!/n";
			return false;
		}
	}

	
	//Advaned Collision check, returns object which was detected as the collider
	GameObject& CollisionComponent::CheckForCollision()
	{
		///Loops through scene object list and checks for a collision with this object [very expensive]
		///Going to need to access the scenemanager, not viable to reference it from application (this is why we used system)
	}

	void CollisionComponent::Init()
	{
	}

	void CollisionComponent::OnBegin()
	{
	}

	void CollisionComponent::OnUpdate()
	{
	}

	void CollisionComponent::OnDisplay()
	{
	}
}