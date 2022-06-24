#pragma once

#include <memory>

struct SDL_Renderer;

namespace KE
{
	class Texture;

	class Renderer
	{
	public:

		static void Submit(const std::shared_ptr<Texture>& _Texture);
		static void Draw(const std::shared_ptr<Texture>& _Texture);

		static void SetClearColour(Uint8 _R, Uint8 _G, Uint8 _B, Uint8 _A);
		static void Clear();

	private:

		static void Init();
		static void Shutdown();

		static SDL_Renderer* m_Renderer;

		friend class System;
	};
}
