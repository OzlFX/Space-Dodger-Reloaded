#pragma once

#include "Core.h"
#include "KeplerEngine/Window/Window.h"
#include "KeplerEngine/Core/LayerManager.h"
#include "KeplerEngine/Scene/SceneManager.h"

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

		void PushLayer(Layer* _Layer) { m_LayerManager->PushLayer(_Layer); }
		void PushOverlay(Layer* _Layer) { m_LayerManager->PushOverlay(_Layer); }

		virtual ~Application();

	private:

		void Run(); //Run the application
		void Close(); //Close the application

		//Application Vars
		bool m_Running; //Run Check
		bool m_Minimised = false; //Minimised Check

		std::unique_ptr<Window> m_Window; //Window
		std::unique_ptr<LayerManager> m_LayerManager; //Instance of the layer manager
		std::unique_ptr<SceneManager> m_SceneManager; //Instance of the scene manager
		static Application* s_Self; //Instance of the application

		friend int ::main();
	};

	std::unique_ptr<Application> CreateApplication(); //Define in client
}
