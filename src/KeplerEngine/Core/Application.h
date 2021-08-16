#pragma once

#include "Core.h"
#include "KeplerEngine/Window/Window.h"

#include <memory>

int main();

namespace KE
{
	class KE_API Application
	{
	public:

		Application();

		Window& GetWindow() { return *m_Window; } //Get the window
		static Application& GetApplication() { return *s_Self; }

		virtual ~Application();

	private:

		void Run(); //Run the application
		void Close(); //Close the application

		//Application Vars
		bool m_Running; //Run Check
		bool m_Minimised = false; //Minimised Check

		float m_LastFrameTime = 0.0f; //Last frame's time set to nothing

		std::unique_ptr<Window> m_Window; //Window
		static Application* s_Self; //Instance of the application

		friend int ::main();
	};

	std::unique_ptr<Application> CreateApplication(); //Define in client
}
