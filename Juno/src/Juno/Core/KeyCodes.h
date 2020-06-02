#pragma once

namespace Juno
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define JUNO_KEY_SPACE           ::Juno::Key::Space
#define JUNO_KEY_APOSTROPHE      ::Juno::Key::Apostrophe    /* ' */
#define JUNO_KEY_COMMA           ::Juno::Key::Comma         /* , */
#define JUNO_KEY_MINUS           ::Juno::Key::Minus         /* - */
#define JUNO_KEY_PERIOD          ::Juno::Key::Period        /* . */
#define JUNO_KEY_SLASH           ::Juno::Key::Slash         /* / */
#define JUNO_KEY_0               ::Juno::Key::D0
#define JUNO_KEY_1               ::Juno::Key::D1
#define JUNO_KEY_2               ::Juno::Key::D2
#define JUNO_KEY_3               ::Juno::Key::D3
#define JUNO_KEY_4               ::Juno::Key::D4
#define JUNO_KEY_5               ::Juno::Key::D5
#define JUNO_KEY_6               ::Juno::Key::D6
#define JUNO_KEY_7               ::Juno::Key::D7
#define JUNO_KEY_8               ::Juno::Key::D8
#define JUNO_KEY_9               ::Juno::Key::D9
#define JUNO_KEY_SEMICOLON       ::Juno::Key::Semicolon     /* ; */
#define JUNO_KEY_EQUAL           ::Juno::Key::Equal         /* = */
#define JUNO_KEY_A               ::Juno::Key::A
#define JUNO_KEY_B               ::Juno::Key::B
#define JUNO_KEY_C               ::Juno::Key::C
#define JUNO_KEY_D               ::Juno::Key::D
#define JUNO_KEY_E               ::Juno::Key::E
#define JUNO_KEY_F               ::Juno::Key::F
#define JUNO_KEY_G               ::Juno::Key::G
#define JUNO_KEY_H               ::Juno::Key::H
#define JUNO_KEY_I               ::Juno::Key::I
#define JUNO_KEY_J               ::Juno::Key::J
#define JUNO_KEY_K               ::Juno::Key::K
#define JUNO_KEY_L               ::Juno::Key::L
#define JUNO_KEY_M               ::Juno::Key::M
#define JUNO_KEY_N               ::Juno::Key::N
#define JUNO_KEY_O               ::Juno::Key::O
#define JUNO_KEY_P               ::Juno::Key::P
#define JUNO_KEY_Q               ::Juno::Key::Q
#define JUNO_KEY_R               ::Juno::Key::R
#define JUNO_KEY_S               ::Juno::Key::S
#define JUNO_KEY_T               ::Juno::Key::T
#define JUNO_KEY_U               ::Juno::Key::U
#define JUNO_KEY_V               ::Juno::Key::V
#define JUNO_KEY_W               ::Juno::Key::W
#define JUNO_KEY_X               ::Juno::Key::X
#define JUNO_KEY_Y               ::Juno::Key::Y
#define JUNO_KEY_Z               ::Juno::Key::Z
#define JUNO_KEY_LEFT_BRACKET    ::Juno::Key::LeftBracket   /* [ */
#define JUNO_KEY_BACKSLASH       ::Juno::Key::Backslash     /* \ */
#define JUNO_KEY_RIGHT_BRACKET   ::Juno::Key::RightBracket  /* ] */
#define JUNO_KEY_GRAVE_ACCENT    ::Juno::Key::GraveAccent   /* ` */
#define JUNO_KEY_WORLD_1         ::Juno::Key::World1        /* non-US #1 */
#define JUNO_KEY_WORLD_2         ::Juno::Key::World2        /* non-US #2 */

/* Function keys */
#define JUNO_KEY_ESCAPE          ::Juno::Key::Escape
#define JUNO_KEY_ENTER           ::Juno::Key::Enter
#define JUNO_KEY_TAB             ::Juno::Key::Tab
#define JUNO_KEY_BACKSPACE       ::Juno::Key::Backspace
#define JUNO_KEY_INSERT          ::Juno::Key::Insert
#define JUNO_KEY_DELETE          ::Juno::Key::Delete
#define JUNO_KEY_RIGHT           ::Juno::Key::Right
#define JUNO_KEY_LEFT            ::Juno::Key::Left
#define JUNO_KEY_DOWN            ::Juno::Key::Down
#define JUNO_KEY_UP              ::Juno::Key::Up
#define JUNO_KEY_PAGE_UP         ::Juno::Key::PageUp
#define JUNO_KEY_PAGE_DOWN       ::Juno::Key::PageDown
#define JUNO_KEY_HOME            ::Juno::Key::Home
#define JUNO_KEY_END             ::Juno::Key::End
#define JUNO_KEY_CAPS_LOCK       ::Juno::Key::CapsLock
#define JUNO_KEY_SCROLL_LOCK     ::Juno::Key::ScrollLock
#define JUNO_KEY_NUM_LOCK        ::Juno::Key::NumLock
#define JUNO_KEY_PRINT_SCREEN    ::Juno::Key::PrintScreen
#define JUNO_KEY_PAUSE           ::Juno::Key::Pause
#define JUNO_KEY_F1              ::Juno::Key::F1
#define JUNO_KEY_F2              ::Juno::Key::F2
#define JUNO_KEY_F3              ::Juno::Key::F3
#define JUNO_KEY_F4              ::Juno::Key::F4
#define JUNO_KEY_F5              ::Juno::Key::F5
#define JUNO_KEY_F6              ::Juno::Key::F6
#define JUNO_KEY_F7              ::Juno::Key::F7
#define JUNO_KEY_F8              ::Juno::Key::F8
#define JUNO_KEY_F9              ::Juno::Key::F9
#define JUNO_KEY_F10             ::Juno::Key::F10
#define JUNO_KEY_F11             ::Juno::Key::F11
#define JUNO_KEY_F12             ::Juno::Key::F12
#define JUNO_KEY_F13             ::Juno::Key::F13
#define JUNO_KEY_F14             ::Juno::Key::F14
#define JUNO_KEY_F15             ::Juno::Key::F15
#define JUNO_KEY_F16             ::Juno::Key::F16
#define JUNO_KEY_F17             ::Juno::Key::F17
#define JUNO_KEY_F18             ::Juno::Key::F18
#define JUNO_KEY_F19             ::Juno::Key::F19
#define JUNO_KEY_F20             ::Juno::Key::F20
#define JUNO_KEY_F21             ::Juno::Key::F21
#define JUNO_KEY_F22             ::Juno::Key::F22
#define JUNO_KEY_F23             ::Juno::Key::F23
#define JUNO_KEY_F24             ::Juno::Key::F24
#define JUNO_KEY_F25             ::Juno::Key::F25

/* Keypad */
#define JUNO_KEY_KP_0            ::Juno::Key::KP0
#define JUNO_KEY_KP_1            ::Juno::Key::KP1
#define JUNO_KEY_KP_2            ::Juno::Key::KP2
#define JUNO_KEY_KP_3            ::Juno::Key::KP3
#define JUNO_KEY_KP_4            ::Juno::Key::KP4
#define JUNO_KEY_KP_5            ::Juno::Key::KP5
#define JUNO_KEY_KP_6            ::Juno::Key::KP6
#define JUNO_KEY_KP_7            ::Juno::Key::KP7
#define JUNO_KEY_KP_8            ::Juno::Key::KP8
#define JUNO_KEY_KP_9            ::Juno::Key::KP9
#define JUNO_KEY_KP_DECIMAL      ::Juno::Key::KPDecimal
#define JUNO_KEY_KP_DIVIDE       ::Juno::Key::KPDivide
#define JUNO_KEY_KP_MULTIPLY     ::Juno::Key::KPMultiply
#define JUNO_KEY_KP_SUBTRACT     ::Juno::Key::KPSubtract
#define JUNO_KEY_KP_ADD          ::Juno::Key::KPAdd
#define JUNO_KEY_KP_ENTER        ::Juno::Key::KPEnter
#define JUNO_KEY_KP_EQUAL        ::Juno::Key::KPEqual

#define JUNO_KEY_LEFT_SHIFT      ::Juno::Key::LeftShift
#define JUNO_KEY_LEFT_CONTROL    ::Juno::Key::LeftControl
#define JUNO_KEY_LEFT_ALT        ::Juno::Key::LeftAlt
#define JUNO_KEY_LEFT_SUPER      ::Juno::Key::LeftSuper
#define JUNO_KEY_RIGHT_SHIFT     ::Juno::Key::RightShift
#define JUNO_KEY_RIGHT_CONTROL   ::Juno::Key::RightControl
#define JUNO_KEY_RIGHT_ALT       ::Juno::Key::RightAlt
#define JUNO_KEY_RIGHT_SUPER     ::Juno::Key::RightSuper
#define JUNO_KEY_MENU            ::Juno::Key::Menu