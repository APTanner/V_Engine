#include "pch.h"
#include "Layer.h"

namespace V_Engine
{
	Layer::Layer(const std::string& name, bool enabled)
		: m_name(name),
		  m_enabled(enabled)
	{
	}

	Layer::~Layer()
	{

	}
}
