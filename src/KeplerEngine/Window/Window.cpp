#include <iostream>
#include "Window.h"

namespace KE
{
	Window::Window(const std::string& _Title, int _XPos, int _YPos,
		unsigned int _Width, unsigned int _Height, bool _Fullscreen, Uint32 _Flags)
		: m_Fullscreen(_Fullscreen)
	{
		m_Window = SDL_CreateWindow(_Title.c_str(), _XPos, _YPos, 
			_Width, _Height, _Flags);
		SetFullscreen(_Fullscreen);

		if (m_Window == NULL)
		{
			std::cout << "ERROR: " << SDL_GetError() << " Unable to create Window!\n";
			throw std::exception();
		}
	}

	void Window::OnUpdate()
	{

	}

	void Window::SetFullscreen(bool _Fullscreen)
	{
		SDL_SetWindowFullscreen(m_Window, _Fullscreen);
	}

	Window::~Window()
	{
		SDL_DestroyWindow(m_Window);
	}
}