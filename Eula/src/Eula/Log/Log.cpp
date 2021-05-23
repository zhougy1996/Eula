#include "eulapch.h"
#include "Eula/Log/Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Eula {

    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    Log::Log()
    {
    }

    Log::~Log()
    {
    }

    void Log::Init()
    {
        //%^ ... %$  color range
        //%T time
        //%n logger name
        //%v actual log text
        spdlog::set_pattern("%^[%T] %n: %v%$");

        //init core logger
        s_CoreLogger = spdlog::stdout_color_mt("Eula");
        s_CoreLogger->set_level(spdlog::level::trace);

        //init client logger
        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);

    }


}
