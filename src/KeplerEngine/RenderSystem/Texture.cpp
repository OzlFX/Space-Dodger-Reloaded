#include <iostream>
#include "Texture.h"

namespace KE
{
	Texture::Texture(const std::string& _File, int _PosX, int _PosY,
		unsigned int _Width, unsigned int _Height)
		: m_Texture(nullptr), m_SurfaceLoader(nullptr)
	{
		m_Data.x = _PosX;
		m_Data.y = _PosY;
		m_Data.w = _Width;
		m_Data.h = _Height;
	
		m_SurfaceLoader = SDL_LoadBMP(_File.c_str());
	
		if (m_SurfaceLoader == nullptr)
		{
			std::cout << "Error: Unable to load image " << _File << "!\n" << SDL_GetError() << "\n";
		}
	}
	
	Texture::Texture(const std::string& _File, glm::vec2 _Position, glm::vec2 _Dimensions)
		: m_Texture(nullptr), m_SurfaceLoader(nullptr)
	{
		m_Data.x = _Position.x;
		m_Data.y = _Position.y;
		m_Data.w = _Dimensions.y;
		m_Data.h = _Dimensions.y;
	
		m_SurfaceLoader = SDL_LoadBMP(_File.c_str());
	
		if (m_SurfaceLoader == nullptr)
		{
			std::cout << "Error: Unable to load image " << _File << "!\n" << SDL_GetError() << "\n";
		}
	}
	
	void Texture::TextureSetup(SDL_Texture* _Texture)
	{
		m_Texture = _Texture;
	}
	
	void Texture::CleanUp()
	{
		SDL_FreeSurface(m_SurfaceLoader);
	}
	
	Texture::~Texture()
	{
		SDL_DestroyTexture(m_Texture);
	}
}
