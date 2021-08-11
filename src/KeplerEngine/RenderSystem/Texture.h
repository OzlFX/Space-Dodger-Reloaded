#pragma once

#include <string>
#include <glm/glm.hpp>
#include <SDL.h>

namespace KE
{
	class Texture
	{
	public:

		Texture(const std::string& _File, int _PosX, int _PosY,
			unsigned int _Width, unsigned int _Height);

		Texture(const std::string& _File, glm::vec2 _Position,
			glm::vec2 _Dimensions);

		void TextureSetup(SDL_Texture* _Texture);

		SDL_Texture& GetTexture() { return *m_Texture; }
		SDL_Surface& GetSurface() { return *m_SurfaceLoader; }
		const SDL_Rect& GetData() const { return m_Data; }
		const glm::vec2& GetDimensions() const { return glm::vec2(m_Data.w, m_Data.h); }

		void CleanUp();

		~Texture();

	private:

		SDL_Texture* m_Texture;
		SDL_Surface* m_SurfaceLoader;
		SDL_Rect m_Data;

	};
}
