#pragma once 

#include <memory>
#include <typeinfo>
#include <typeindex> // For std::type_index
#include <unordered_set>

#include "Core/Core.h"

#include "ComponentStorage.h"

namespace V_Engine
{
	class ComponentManager
	{
	public:
		template<typename T>
		void RegisterComponentType()
		{
			V_ASSERT(m_validComponents.find(typeid(T)) == m_validComponents.end(), "Cannot register the same component twice");
			m_validComponents.insert(typeid(T));
			m_componentStorages[typeid(T)] = std::make_unique<T>();
		}

		template<typename T>
		void AddComponent(Entity entity, const T& component)
		{
			GetComponentStorage<T>()->AddComponent(entity, component);
		}

		template<typename T>
		void RemoveComponent(Entity entity)
		{
			GetComponentStorage<T>()->RemoveComponent(entity);
		}

		template<typename T> 
		T& GetComponent(Entity entity) const
		{
			return GetComponentStorage<T>()->GetComponent(entity);
		}
	private:
		template<typename T>
		ComponentStorage* GetComponentStorage()
		{
			V_ASSERT(m_validComponents.find(typeid(T)) != m_validComponents.end(), "Invalid Component: No storage");

			return dynamic_cast<T*>(m_componentStorages.find(typeid(T)).get());
		}
	private:
		std::unordered_map<std::type_index, std::unique_ptr<ComponentStorage>> m_componentStorages{};
		std::unordered_set<std::type_index> m_validComponents{};
		Component m_nextComponentType = 0;
	};
}