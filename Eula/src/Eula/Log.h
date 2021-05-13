#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Eula {

	class EULA_API Log
	{
	public:
		Log();
		~Log();

		static void Init();
		static inline std::shared_ptr<spdlog::logger> GetCoreLogger() { return s_CoreLogger; };
		static inline std::shared_ptr<spdlog::logger> GetClientLogger() { return s_ClientLogger; };

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}


#define EULA_CORE_TRACE(...)	Eula::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EULA_CORE_INFO(...)		Eula::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EULA_CORE_WARN(...)		Eula::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EULA_CORE_ERROR(...)	Eula::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EULA_CORE_FATAL(...)	Eula::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define EULA_TRACE(...)		Eula::Log::GetClientLogger()->trace(__VA_ARGS__)
#define EULA_INFO(...)		Eula::Log::GetClientLogger()->info(__VA_ARGS__)
#define EULA_WARN(...)		Eula::Log::GetClientLogger()->warn(__VA_ARGS__)
#define EULA_ERROR(...)		Eula::Log::GetClientLogger()->error(__VA_ARGS__)
#define EULA_FATAL(...)		Eula::Log::GetClientLogger()->critical(__VA_ARGS__)
