#pragma once

#include "Juno/Scene/Scene.h"
#include "Juno/Core/Core.h"
#include "Juno/Scene/Entity.h"

namespace Juno
{
	class SceneHierarchyPanel
	{
		public:
			SceneHierarchyPanel() = default;
			SceneHierarchyPanel(const Ref<Scene>& scene);

			void SetContext(const Ref<Scene>& scene);

			void OnImGuiRender();

			Entity GetSelectedEntity() const { return m_SelectionContext; };

		private:
			void DrawEntityNode(Entity entity);
			void DrawComponents(Entity entity);

			Ref<Scene> m_Context;
			Entity m_SelectionContext;
	};
}
