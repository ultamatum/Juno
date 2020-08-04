#pragma once

#include "Juno/Core/Core.h"
#include "Juno/Core/KeyCodes.h"
#include "Juno/Core/MouseCodes.h"

namespace Juno
{
	class Input
	{
		public:
			static bool IsKeyPressed(KeyCode key);

			static bool IsMouseButtonPressed(MouseCode button);
			static std::pair<float, float> GetMousePosition();
			static float GetMouseX();
			static float GetMouseY();
	};
}