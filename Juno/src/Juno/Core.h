#pragma once

#ifdef JUNO_PLATFORM_WINDOWS
#if JUNO_DYNAMIC_LINK
		#ifdef JUNO_BUILD_DLL
			#define JUNO_API __declspec(dllexport)
		#else
			#define JUNO_API __declspec(dllimport)
		#endif
	#else
		#define JUNO_API
	#endif
#else
	#error Juno only supports Windows!
#endif	

#ifdef JUNO_DEBUG
	#define JUNO_ENABLE_ASSERTS
#endif  

//Assertion used primarily for debugging purposes, to be disabled for end client
#ifdef JUNO_ENABLE_ASSERTS
	#define JUNO_ASSERT(x, ...) { if(!(x)) { JUNO_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define JUNO_CORE_ASSERT(x, ...) { if(!(x)) { JUNO_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define JUNO_ASSERT(x, ...)
	#define JUNO_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define JUNO_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)