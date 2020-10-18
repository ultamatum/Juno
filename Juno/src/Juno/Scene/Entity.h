#pragma once

#include "Scene.h"

#include "entt.hpp"

namespace Juno
{
	class Entity
	{
		public:
			Entity() = default;
			Entity(entt::entity handle, Scene* scene);
			Entity(const Entity& other) = default;

			template<typename T, typename... Args>
			T& AddComponent(Args&&... args)
			{
				JUNO_CORE_ASSERT(!HasComponent<T>(), "Entity already has component");

				return m_Scene->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
			}

			template<typename T>
			T& GetComponent()
			{
				JUNO_CORE_ASSERT(HasComponent<T>(), "Entity doesn't have component");

				return m_Scene->m_Registry.get<T>(m_EntityHandle);
			}

			template<typename T>
			bool HasComponent()
			{
				return m_Scene->m_Registry.has<T>(m_EntityHandle);
			}
			
			template<typename T>
			void RemoveComponent()
			{
				JUNO_CORE_ASSERT(HasComponent<T>(), "Entity doesn't have component");

				m_Scene->m_Registry.remove<T>(m_EntityHandle);
			}

			operator bool() const { return m_EntityHandle != entt::null; };

		private:
			entt::entity m_EntityHandle{ entt::null };
			Scene* m_Scene = nullptr;
	};

}
