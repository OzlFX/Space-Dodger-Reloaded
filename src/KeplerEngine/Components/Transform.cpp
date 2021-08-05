#include "Transform.h"

namespace KE
{
	void Transform::Init(float _PosX, float _PosY, float _RotX, float _RotY)
	{
		Position.x = _PosX;
		Position.y = _PosY;
		Rotation.x = _RotX;
		Rotation.y = _RotY;
	}

	void Transform::Init(glm::vec2 _Position, glm::vec2 _Rotation)
	{
		Position = _Position;
		Rotation = _Rotation;
	}
}
