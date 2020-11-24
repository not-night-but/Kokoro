#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Kokoro {
  class Log {
   public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

   private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
  };
}  // namespace Kokoro

// Core log macros
#define KO_CORE_TRACE(...)    ::Kokoro::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KO_CORE_INFO(...)     ::Kokoro::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KO_CORE_WARN(...)     ::Kokoro::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KO_CORE_ERROR(...)    ::Kokoro::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KO_CORE_FATAL(...)    ::Kokoro::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define KO_TRACE(...)         ::Kokoro::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KO_INFO(...)          ::Kokoro::Log::GetClientLogger()->info(__VA_ARGS__)
#define KO_WARN(...)          ::Kokoro::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KO_ERROR(...)         ::Kokoro::Log::GetClientLogger()->error(__VA_ARGS__)
#define KO_FATAL(...)         ::Kokoro::Log::GetClientLogger()->fatal(__VA_ARGS__)
