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

#define JUNO_EXPAND_MACRO(x) x
#define JUNO_STRINGIFY_MACRO(x) #x

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

#include "Juno/Core/Log.h"
#include "Juno/Core/Assert.h"
