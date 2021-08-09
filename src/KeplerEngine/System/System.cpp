#include "System.h"

namespace KE
{
	void System::MoveObject(std::shared_ptr<GameObject>& _Object)
	{

	}

	void System::Draw(std::shared_ptr<Texture>& _Texture)
	{
		Renderer::Submit(_Texture);
	}
}
