#pragma once

#include "entt.hpp"

namespace Juno
{
	class Scene
	{
		public:
			Scene();
			~Scene();

		private:
			entt::registry m_Registry;
	};
}