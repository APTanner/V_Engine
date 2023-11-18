#pragma once 

#include <vector>
#include <unordered_map>

#include "Entity.h"

namespace V_Engine
{
	class ComponentStorage
	{
	public:
		ComponentStorage() {};
		virtual ~ComponentStorage() = default;
	};

	template<typename T>
	class ComponentTypeStorage : public ComponentStorage
	{
	public:
		ComponentTypeStorage() : ComponentStorage() {}

		void AddComponent(Entity entity, const T& component)
		{
			size_t index = m_componentAmount;
			m_entityToIndex[entity] = index;
			m_components[index] = component;
			m_indexToEntity[index] = entity;
			++m_componentAmount;
		}

		void RemoveComponent(Entity entity)
		{
			size_t index = m_entityToIndex[entity];
			size_t lastComponentIndex = --m_componentAmount;
			Entity movingEntity = m_indexToEntity[index];
			m_entityToIndex.erase(entity);
			m_entityToIndex[movingEntity] = index;
			m_indexToEntity[index] = movingEntity;
			m_components[index] = m_components[lastComponentIndex];
		}

		T& GetComponent(Entity entity)
		{
			return m_components[m_entityToIndex[entity]];
		}
	private:
		std::vector<T> m_components = std::vector<T>(MAX_ENTITIES);
		std::vector<Entity> m_indexToEntity = std::vector<Entity>(MAX_ENTITIES);
		std::unordered_map<Entity, size_t> m_entityToIndex{};
		int m_componentAmount{};
	};
}