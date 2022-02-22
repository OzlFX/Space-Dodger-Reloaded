#include "LayerManager.h"
#include "Layer.h"

namespace KE
{
	void LayerManager::PushLayer(Layer* _Layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, _Layer);
		m_LayerInsertIndex++;
	}

	void LayerManager::PushOverlay(Layer* _Layer)
	{
		m_Layers.emplace_back(_Layer);
	}

	void LayerManager::PopLayer(Layer* _Layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIndex, _Layer);
		if (it != m_Layers.begin() + m_LayerInsertIndex)
		{
			_Layer->OnDetach();
			m_Layers.erase(it);
			m_LayerInsertIndex--;
		}
	}

	void LayerManager::PopOverlay(Layer* _Overlay)
	{
		auto it = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(), _Overlay);
		if (it != m_Layers.end())
		{
			_Overlay->OnDetach();
			m_Layers.erase(it);

		}
	}

	LayerManager::~LayerManager()
	{
		for (Layer* layer : m_Layers)
		{
			layer->OnDetach();
			delete layer;
		}
	}
}