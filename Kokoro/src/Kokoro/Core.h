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

#define BIT(x) (1 << x)
