#include <SDL.h>
#include <iostream>
#include "Texture.h"
#include "Renderer.h"

namespace KE
{
	void Renderer::Init()
	{
		//Initialise SDL
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			//if SDL fails to initialises, an error is returned to the console and closes the game
			std::cout << "ERROR: " << SDL_GetError() << "\nUnable to initialize SDL!" << std::endl;
			throw std::exception();
		}
	}

	void Renderer::Shutdown()
	{
		SDL_DestroyRenderer(m_Renderer);
	}

	void Renderer::Submit(const std::shared_ptr<Texture>& _Texture)
	{
		_Texture->TextureSetup(SDL_CreateTextureFromSurface(
			m_Renderer,
			&_Texture->GetSurface()));
		_Texture->CleanUp();
	}

	void Renderer::SetClearColour(Uint8 _R, Uint8 _G, Uint8 _B, Uint8 _A)
	{
		SDL_SetRenderDrawColor(m_Renderer, _R, _G, _B, _A);
	}

	void Renderer::Clear()
	{
		SDL_RenderClear(m_Renderer);
	}

	void Renderer::Draw(const std::shared_ptr<Texture>& _Texture)
	{
		SDL_RenderCopy(m_Renderer, &_Texture->GetTexture(), NULL, &_Texture->GetData());
	}
}
