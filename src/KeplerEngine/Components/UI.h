#pragma once

#include <KeplerEngine/Components/Base/Components.h>
#include <unordered_map>

struct SDL_Rect;

namespace KE
{
	class UI : public Component
	{
	public:

		UI();

		bool OnUIElementEnter(std::shared_ptr<GameObject>& _Button);
		bool OnButtonPressed();
		bool OnButtonReleased();

		const SDL_Rect& GetUIBounds() const { return *m_UIBounds; }

	private:

		const SDL_Rect& CacheBounds(std::shared_ptr<GameObject>& _Button);

		int m_MousePosX, m_MousePosY;
		std::unordered_map<std::shared_ptr<GameObject>&, SDL_Rect&> m_BoundCache;
		const SDL_Rect* m_UIBounds;

	};
}