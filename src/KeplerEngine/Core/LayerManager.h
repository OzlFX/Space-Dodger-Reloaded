#pragma once

#include <vector>

class Layer;

namespace KE
{
	class LayerManager
	{
	public:

		LayerManager() = default;

		void PushLayer(Layer* _Layer);
		void PushOverlay(Layer* _Overlay);
		void PopLayer(Layer* _Layer);
		void PopOverlay(Layer* _Overlay);

		~LayerManager();

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

		std::vector<Layer*>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
		std::vector<Layer*>::reverse_iterator rend() { return m_Layers.rend(); }

		std::vector<Layer*>::const_iterator begin() const { return m_Layers.begin(); }
		std::vector<Layer*>::const_iterator end() const { return m_Layers.end(); }

		std::vector<Layer*>::const_reverse_iterator rbegin() const { return m_Layers.rbegin(); }
		std::vector<Layer*>::const_reverse_iterator rend() const { return m_Layers.rend(); }

	private:

		std::vector<Layer*> m_Layers;
		unsigned int m_LayerInsertIndex = 0;

	};
}
