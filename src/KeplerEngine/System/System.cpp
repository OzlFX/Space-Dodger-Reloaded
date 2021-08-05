#include "System.h"

namespace KE
{
	void System::Draw(std::shared_ptr<Texture>& _Texture)
	{
		Renderer::Submit(_Texture);
	}
}
