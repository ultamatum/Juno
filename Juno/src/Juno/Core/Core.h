#pragma once

#include <memory>

#include "PlatformDetection.h"

//DLL support
#ifdef JUNO_DEBUG
	#if defined(JUNO_PLATFORM_WINDOWS)
		#define JUNO_DEBUGBREAK() __debugbreak()
	#elif defined(JUNO_PLATFORM_LINUX)
		#include <signal.h>
		#define JUNO_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define JUNO_ENABLE_ASSERTS
#else
	#define JUNO_DEBUGBREAK()
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

#define JUNO_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) {return this->fn(std::forward<decltype(args)>(args)...);}

namespace Juno
{
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}