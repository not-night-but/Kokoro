workspace "Kokoro"
  architecture "x64"

  configurations {
    "Debug",
    "Release",
    "Dist"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Kokoro/vendor/GLFW/include"
IncludeDir["Glad"] = "Kokoro/vendor/Glad/include"

include "Kokoro/vendor/GLFW"
include "Kokoro/vendor/Glad"

project "Kokoro"
  location "Kokoro"
  kind "SharedLib"
  language "C++"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  pchheader "kopch.h"
  --if using visual studio at some point, add a pchsource

  files {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
  }

  includedirs {
    "%{prj.name}/src",
    "%{prj.name}/vendor/spdlog/include",
    "%{IncludeDir.GLFW}",
    "%{IncludeDir.Glad}"
  }

  links {
    "GLFW",
    "Glad"
  }

  filter "system:linux"
    buildoptions { "-std=c++17", "-g", "-fPIC"}

    defines {
      "KO_PLATFORM_LINUX",
      "KO_BUILD_SO",
      "GLFW_INCLUDE_NONE"
    }

    links {
      "GL"
    }

    postbuildcommands {
      ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
    }

  filter "configurations:Debug"
    defines "KO_DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "KO_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "KO_DIST"
    symbols "On"

project "Sandbox"
  location "Sandbox"
  kind "ConsoleApp"
  language "C++"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  files {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
  }

  includedirs {
    "Kokoro/vendor/spdlog/include",
    "Kokoro/src"
  }

  links {
    "Kokoro"
  }

  filter "system:linux"
    buildoptions { "-std=c++17", "-g", "`pkg-config --cflags sdl2`"}

    linkoptions {
      "`pkg-config --libs sdl2`",
      "-lSDL2_image",
      "-lm"
    }

    defines {
      "KO_PLATFORM_LINUX"
    }

  filter "configurations:Debug"
    defines "KO_DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "KO_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "KO_DIST"
    symbols "On"
