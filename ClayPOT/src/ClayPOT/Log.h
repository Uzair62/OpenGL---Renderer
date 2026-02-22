#pragma once
#include "macros.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>

namespace cp
{
	class CP_API Log
	{
	public:
		static void init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return cp_coreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return cp_clientLogger; }

	private:

		static std::shared_ptr<spdlog::logger> cp_coreLogger;
		static std::shared_ptr<spdlog::logger> cp_clientLogger;

	};
}

#define CP_CORE_TRACE(...)    ::cp::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CP_CORE_INFO(...)     ::cp::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CP_CORE_WARN(...)     ::cp::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CP_CORE_ERROR(...)    ::cp::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CP_CORE_FATAL(...)    ::cp::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define CP_TRACE(...)         ::cp::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CP_INFO(...)          ::cp::Log::GetClientLogger()->info(__VA_ARGS__)
#define CP_WARN(...)          ::cp::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CP_ERROR(...)         ::cp::Log::GetClientLogger()->error(__VA_ARGS__)
#define CP_FATAL(...)         ::cp::Log::GetClientLogger()->critical(__VA_ARGS__)