#pragma once

#include <string>
#include "KeplerEngine/Components/Base/Components.h"

namespace KE
{
	class Texture;

	class RenderComponent : public Component
	{
	public:



	private:

		void Init(const std::string& _File, unsigned int _Width, unsigned int _Height);
		void OnBegin();
		void OnUpdate();
		void OnDisplay();

		std::shared_ptr<Texture> m_Texture;

	};
}