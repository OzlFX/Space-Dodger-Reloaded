#include "Application.h"
#include "KeplerEngine/RenderSystem/Renderer.h"
#include "Time.h"
#include "Event.h"

namespace KE
{
	Application* Application::s_Self = nullptr;

	Application::Application()
		: m_Running(true)
	{
		Renderer::Init();
		m_Window = Window::CreateWindow("Space Dodger: Reloaded", 
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			1200, 800, false);
		s_Self = this;
	}

	void Application::Run()
	{
		while (SDL_PollEvent(Event::m_Event))
		{
			Time _T((float)SDL_GetTicks());

			//Close the application on sdl close event
			if (Event::m_Event->type == SDL_QUIT)
				Close();
		}
	}

	void Application::Close()
	{
		m_Running = false;
	}

	Application::~Application()
	{
		Renderer::Shutdown();
	}
}