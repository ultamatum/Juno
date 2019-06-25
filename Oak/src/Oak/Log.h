#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Oak {
	class OAK_API Log
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
#define OK_CORE_TRACE(...)     ::Oak::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define OK_CORE_INFO(...)      ::Oak::Log::GetCoreLogger()->info(__VA_ARGS__);
#define OK_CORE_WARN(...)      ::Oak::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define OK_CORE_ERROR(...)     ::Oak::Log::GetCoreLogger()->error(__VA_ARGS__);
#define OK_CORE_FATAL(...)     ::Oak::Log::GetCoreLogger()->fatal(__VA_ARGS__);

// Client Log Macros
#define OK_TRACE(...)          ::Oak::Log::GetClientLogger()->trace(__VA_ARGS__);
#define OK_INFO(...)           ::Oak::Log::GetClientLogger()->info(__VA_ARGS__);
#define OK_WARN(...)           ::Oak::Log::GetClientLogger()->warn(__VA_ARGS__);
#define OK_ERROR(...)          ::Oak::Log::GetClientLogger()->error(__VA_ARGS__);
#define OK_FATAL(...)          ::Oak::Log::GetClientLogger()->fatal(__VA_ARGS__);