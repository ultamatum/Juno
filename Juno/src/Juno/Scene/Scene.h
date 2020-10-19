#pragma once

#include "entt.hpp"

#include "Juno/Core/Timestep.h"

namespace Juno
{
	class Entity;

	class Scene
	{
		public:
			Scene();
			~Scene();

			Entity CreateEntity(const std::string& name = std::string());

			// TEMP
			entt::registry& Reg() { return m_Registry; };

			void OnUpdate(Timestep ts);
			void OnViewportResize(uint32_t width, uint32_t height);
		private:
			entt::registry m_Registry;
			uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;

			friend class Entity;
			friend class SceneHierarchyPanel;
	};
}
