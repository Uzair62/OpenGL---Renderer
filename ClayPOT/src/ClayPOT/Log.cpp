#include "cph.h"
#include "Log.h"

namespace cp
{

	std::shared_ptr<spdlog::logger> Log::cp_coreLogger;
	std::shared_ptr<spdlog::logger> Log::cp_clientLogger;

	void Log::init()
	{

		spdlog::set_pattern("%^[%T] %n: %v%$");
		cp_coreLogger = spdlog::stdout_color_mt("CLAYPOT");
		cp_coreLogger->set_level(spdlog::level::trace);

		cp_clientLogger = spdlog::stdout_color_mt("APP");
		cp_clientLogger->set_level(spdlog::level::trace);

	}
}