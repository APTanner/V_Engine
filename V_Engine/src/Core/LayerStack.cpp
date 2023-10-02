#include "pch.h"
#include "LayerStack.h"

namespace V_Engine
{
	LayerStack::LayerStack()
	{
		m_layers = std::vector<Layer*>{};
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_layers)
		{
			layer->OnDetach();
			delete layer;
		}
	}

	void LayerStack::Push(Layer* layer)
	{
		m_layers.insert(m_layers.begin() + m_overlayStart, layer);
		layer->OnAttach();
		++m_overlayStart;
	}

	void LayerStack::Pop(Layer* layer)
	{
		auto it_layerEnd = m_layers.begin() + m_overlayStart;
		auto it = std::find(m_layers.begin(), it_layerEnd, layer);
		if (it != it_layerEnd)
		{
			(*it)->OnDetach();
			m_layers.erase(it);
			--m_overlayStart;
		}
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_layers.push_back(overlay);
		overlay->OnAttach();
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_layers.begin()+m_overlayStart, m_layers.end(), overlay);
		if (it != m_layers.end())
		{
			(*it)->OnDetach();
			m_layers.erase(it);
		}
	}
}