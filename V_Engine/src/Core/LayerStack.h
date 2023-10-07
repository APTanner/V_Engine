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

		inline std::vector<Layer*>::iterator begin() { return m_layers.begin(); }
		inline std::vector<Layer*>::iterator end() { return m_layers.end(); }
	private:
		std::vector<Layer*> m_layers;
		int m_overlayStart = 0;
	};
}

