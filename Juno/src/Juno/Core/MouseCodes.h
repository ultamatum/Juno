#pragma once

namespace Juno
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define JUNO_MOUSE_BUTTON_0      ::Juno::Mouse::Button0
#define JUNO_MOUSE_BUTTON_1      ::Juno::Mouse::Button1
#define JUNO_MOUSE_BUTTON_2      ::Juno::Mouse::Button2
#define JUNO_MOUSE_BUTTON_3      ::Juno::Mouse::Button3
#define JUNO_MOUSE_BUTTON_4      ::Juno::Mouse::Button4
#define JUNO_MOUSE_BUTTON_5      ::Juno::Mouse::Button5
#define JUNO_MOUSE_BUTTON_6      ::Juno::Mouse::Button6
#define JUNO_MOUSE_BUTTON_7      ::Juno::Mouse::Button7
#define JUNO_MOUSE_BUTTON_LAST   ::Juno::Mouse::ButtonLast
#define JUNO_MOUSE_BUTTON_LEFT   ::Juno::Mouse::ButtonLeft
#define JUNO_MOUSE_BUTTON_RIGHT  ::Juno::Mouse::ButtonRight
#define JUNO_MOUSE_BUTTON_MIDDLE ::Juno::Mouse::ButtonMiddle