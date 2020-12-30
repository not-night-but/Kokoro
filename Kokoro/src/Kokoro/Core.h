#pragma once

#ifdef KO_PLATFORM_WINDOWS
#elif KO_PLATFORM_LINUX
#else
  #ifndef CCLS
    #error Kokoro Does not support your system!!
  #endif
#endif

#ifdef KO_DEBUG
  #define KO_ENABLE_ASSERTS
#endif

#ifdef KO_ENABLE_ASSERTS
  #define KO_ASSERT(x, ...) { if (!(x)) { KO_ERROR("Assertion Failed: {0}", __VA_ARGS__); __builtin_trap(); }}
  #define KO_CORE_ASSERT(x, ...) { if (!(x)) { KO_ERROR("Assertion Failed: {0}", __VA_ARGS__); __builtin_trap(); }}
#else
  #define KO_ASSERT(x, ...)
  #define KO_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define KO_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
