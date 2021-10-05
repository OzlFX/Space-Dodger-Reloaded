#include "Application.h"
#include "KeplerEngine/RenderSystem/Renderer.h"
#include "Time.h"

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
		while (m_Running)
		{
			Time _T((float)SDL_GetTicks());
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