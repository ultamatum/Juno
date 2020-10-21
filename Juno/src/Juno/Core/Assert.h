#pragma once

#include "Juno/Core/Core.h"
#include "Juno/Core/Log.h"
#include <filesystem>

#ifdef JUNO_ENABLE_ASSERTS

	#define JUNO_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { JUNO##type##ERROR(msg, __VA_ARGS__); JUNO_DEBUGBREAK(); } }
	#define JUNO_INTERNAL_ASSERT_WITH_MSG(type, check, ...) JUNO_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define JUNO_INTERNAL_ASSERT_NO_MSG(type, check) JUNO_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", JUNO_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define JUNO_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define JUNO_INTERNAL_ASSERT_GET_MACRO(...) JUNO_EXPAND_MACRO( JUNO_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, JUNO_INTERNAL_ASSERT_WITH_MSG, JUNO_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define JUNO_ASSERT(...) JUNO_EXPAND_MACRO( JUNO_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define JUNO_CORE_ASSERT(...) JUNO_EXPAND_MACRO( JUNO_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define JUNO_ASSERT(...)
	#define JUNO_CORE_ASSERT(...)
#endif
