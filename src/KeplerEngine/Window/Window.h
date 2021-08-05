#pragma once

#include <string>
#include <memory>
#include <SDL.h>

namespace KE
{
	class Window
	{
	public:

		Window(const std::string& _Title, int _XPos, int _YPos, 
			unsigned int _Width, unsigned int _Height, bool _Fullscreen, Uint32 _Flags);
		
		static std::unique_ptr<Window> CreateWindow(const std::string& _Title, int _XPos, int _YPos,
			unsigned int _Width, unsigned int _Height, bool _Fullscreen, Uint32 _Flags = SDL_WINDOW_OPENGL)
		{
			return std::make_unique<Window>(_Title, _XPos, _YPos, 
				_Width, _Height, _Fullscreen, _Flags);
		}

		void OnUpdate();

		void SetFullscreen(bool _Fullscreen);

		bool IsFullscreen() { return m_Fullscreen; }

		~Window();

	private:

		SDL_Window* m_Window;
		bool m_Fullscreen;
	};
}
