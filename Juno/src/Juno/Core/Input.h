#pragma once

#include <glm/glm.hpp>
#include "Juno/Core/KeyCodes.h"
#include "Juno/Core/MouseCodes.h"

namespace Juno
{
	class Input
	{
		public:
			static bool IsKeyPressed(KeyCode key);

			static bool IsMouseButtonPressed(MouseCode button);
			static glm::vec2 GetMousePosition();
			static float GetMouseX();
			static float GetMouseY();
	};
}
