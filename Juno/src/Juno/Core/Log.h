#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Juno
{
	class JUNO_API Log
	{
		public:
			static void Init();

			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

		private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core Log Macros
#define JUNO_CORE_TRACE(...)     ::Juno::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define JUNO_CORE_INFO(...)      ::Juno::Log::GetCoreLogger()->info(__VA_ARGS__);
#define JUNO_CORE_WARN(...)      ::Juno::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define JUNO_CORE_ERROR(...)     ::Juno::Log::GetCoreLogger()->error(__VA_ARGS__);
#define JUNO_CORE_FATAL(...)     ::Juno::Log::GetCoreLogger()->fatal(__VA_ARGS__);

// Client Log Macros
#define JUNO_TRACE(...)          ::Juno::Log::GetClientLogger()->trace(__VA_ARGS__);
#define JUNO_INFO(...)           ::Juno::Log::GetClientLogger()->info(__VA_ARGS__);
#define JUNO_WARN(...)           ::Juno::Log::GetClientLogger()->warn(__VA_ARGS__);
#define JUNO_ERROR(...)          ::Juno::Log::GetClientLogger()->error(__VA_ARGS__);
#define JUNO_FATAL(...)          ::Juno::Log::GetClientLogger()->fatal(__VA_ARGS__);