#pragma once

#include <stdint.h>
#include <bitset>

#include "Component.h"

constexpr int MAX_ENTITIES = 4000;

namespace V_Engine
{
	using Entity = uint32_t;
	using Inventory = std::bitset<MAX_COMPONENT_TYPES>;
}