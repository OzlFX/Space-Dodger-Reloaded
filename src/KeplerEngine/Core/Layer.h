#pragma once

#include <KeplerEngine/Core/Time.h>
#include <string>
#include <SDL.h>

namespace KE
{
	class Layer
	{
	public:

		Layer(const std::string& _Name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnRender() {}
		virtual void OnEvent(SDL_Event& _Event) {}

		const std::string& GetName() const { return m_DebugName; }

	protected:

		std::string m_DebugName;

	};
}
