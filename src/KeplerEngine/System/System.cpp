#include "System.h"

namespace KE
{
	void System::Draw(std::shared_ptr<Texture>& _Texture)
	{
		KE::Renderer::Submit(_Texture);
	}
}
