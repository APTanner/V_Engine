#pragma once

#include "pch.h"
#include "Layer.h"

namespace V_Engine 
{
	class LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void Push(Layer* layer);
		void Pop(Layer* layer);

		void PushOverlay(Layer* layer);
		void PopOverlay(Layer* layer);

		inline std::vector<Layer*>::iterator layerBegin() { return m_layers.begin(); }
		inline std::vector<Layer*>::iterator layerEnd() { return m_layers.end(); }

		inline std::vector<Layer*>::iterator overlayBegin() { return m_overlays.begin(); }
		inline std::vector<Layer*>::iterator overlayEnd() { return m_overlays.end(); }
	private:
		std::vector<Layer*> m_layers;
		std::vector<Layer*> m_overlays;
	};
}

