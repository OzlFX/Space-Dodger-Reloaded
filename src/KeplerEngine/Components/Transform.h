#pragma once

#include <glm/glm.hpp>
#include "Base/Components.h"

namespace KE
{
	class GameObject;

	class Transform : public Component
	{
	public:

		glm::vec2 Position;
		glm::vec2 Rotation;

	private:

		void Init(float _PosX, float _PosY, float _RotX, float _RotY);
		void Init(glm::vec2 _Position, glm::vec2 _Rotation);

		friend class GameObject;
	};
}