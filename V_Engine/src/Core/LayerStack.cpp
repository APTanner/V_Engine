#include "pch.h"
#include "LayerStack.h"

namespace V_Engine
{
	LayerStack::LayerStack()
	{
		m_layers = std::vector<Layer*>{};
		m_overlays = std::vector<Layer*>{};
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_layers)
		{
			layer->OnDetach();
			delete layer;
		}
		for (Layer* overlay : m_overlays)
		{
			overlay->OnDetach();
			delete overlay;
		}
	}

	void LayerStack::Push(Layer* layer)
	{
		m_layers.push_back(layer);
		layer->OnAttach();
	}

	void LayerStack::Pop(Layer* layer)
	{
		auto it = std::find(m_layers.begin(), m_layers.end(), layer);
		if (it != m_layers.end())
		{
			(*it)->OnDetach();
			m_layers.erase(it);
		}
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_overlays.push_back(overlay);
		overlay->OnAttach();
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_overlays.begin(), m_overlays.end(), overlay);
		if (it != m_overlays.end())
		{
			(*it)->OnDetach();
			m_overlays.erase(it);
		}
	}
}