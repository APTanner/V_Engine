#pragma once

#include <queue>
#include <vector>

#include "Core/Core.h"

#include "Entity.h"
#include "Component.h"

namespace V_Engine
{
	class EntityManager
	{
	public:
		EntityManager()
		{
			for (Entity entity = 0; entity < MAX_ENTITIES; ++entity)
			{
				m_openEntitySlots.push(entity);
			}
		}

		Entity Instantiate()
		{
			V_ASSERT(m_currentEntities < MAX_ENTITIES, "Not enough entity slots");

			Entity entity = m_openEntitySlots.front();
			m_openEntitySlots.pop();
			++m_currentEntities;
			return entity;
		}

		void DeleteEntity(const Entity entity)
		{
			V_ASSERT(entity < MAX_ENTITIES, "Invalid entity");

			//reset the bitset
			m_inventories[entity].reset();
			m_openEntitySlots.push(entity);
			--m_currentEntities;
		}

		Inventory GetInventory(Entity entity) const
		{
			V_ASSERT(entity < MAX_ENTITIES, "Invalid entity");

			return m_inventories[entity];
		}

		void UpdateInventory(Entity entity, Inventory inventory)
		{
			V_ASSERT(entity < MAX_ENTITIES, "Invalid entity");
			V_ASSERT(m_inventories[entity].none(), "Invalid entity");

			m_inventories[entity] = inventory;
		}
	private:
		std::queue<Entity> m_openEntitySlots{};
		std::vector<Inventory> m_inventories = std::vector<Inventory>(MAX_ENTITIES, 0);
		int m_currentEntities = 0;
	};
}