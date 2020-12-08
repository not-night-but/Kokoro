#pragma once

#ifdef KO_PLATFORM_WINDOWS
  #ifdef KO_BUILD_DLL
    #define KOKORO_API __declspec(dllexport)
  #else
    #define KOKORO_API __declspec(dllimport)
  #endif
#elif KO_PLATFORM_LINUX
  #define KOKORO_API
#else
  #ifndef CCLS
    #error Kokoro Does not support your system!!
  #else
    #define KOKORO_API
  #endif
#endif

#ifdef KO_DEBUG
  #define KO_ENABLE_ASSERTS
#endif

#ifdef KO_ENABLE_ASSERTS
  #define KO_ASSERT(x, ...) { if(!(x)) { KO_ERROR("Assertion Failed: {0}", __VA_ARGS__); __builtin_trap(); }}
  #define KO_CORE_ASSERT(x, ...) { if(!(x)) { KO_ERROR("Assertion Failed: {0}", __VA_ARGS__); __builtin_trap(); }}
#else
  #define KO_ASSERT(x, ...)
  #define KO_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define KO_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
