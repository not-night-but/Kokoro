workspace "Kokoro"
	architecture "x64"
	startproject "Sandbox"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Kokoro/vendor/GLFW/include"
IncludeDir["Glad"] = "Kokoro/vendor/Glad/include"
IncludeDir["ImGui"] = "Kokoro/vendor/imgui"
IncludeDir["glm"] = "Kokoro/vendor/glm"

group "Dependencies"
	include "Kokoro/vendor/GLFW"
	include "Kokoro/vendor/Glad"
	include "Kokoro/vendor/imgui"

group ""

project "Kokoro"
	location "Kokoro"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "kopch.h"
	--if using visual studio at some point, add a pchsource

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links {
		"GLFW",
		"Glad",
		"ImGui"
	}

	filter "system:linux"
		defines {
			"KO_PLATFORM_LINUX",
			"GLFW_INCLUDE_NONE"
		}

		links {
			"GL"
		}

	filter "configurations:Debug"
		defines "KO_DEBUG"
		runtime "Debug"
		symbols "on"

	filter { "configurations:Debug", "system:linux" }
		buildoptions { "-std=c++17", "-g", "-fPIC"}

	filter "configurations:Release"
		defines "KO_RELEASE"
		runtime "Release"
		optimize "on"

	filter { "configurations:Release", "system:linux" }
		buildoptions { "-std=c++17", "-fPIC"}

	filter "configurations:Dist"
		defines "KO_DIST"
		runtime "Release"
		optimize "on"

	filter { "configurations:Dist", "system:linux" }
		buildoptions { "-std=c++17", "-fPIC"}

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Kokoro/vendor/spdlog/include",
		"Kokoro/src",
		"Kokoro/vendor",
		"%{IncludeDir.glm}"
	}

	links {
		"Kokoro"
	}

	filter "system:linux"
		buildoptions { "-std=c++17", "-g" }

		links {
			"GLFW",
			"Glad",
			"ImGui",
			"Xrandr",
			"Xi",
			"GLU",
			"GL",
			"X11",
			"dl",
			"pthread",
			"stdc++fs",	--GCC versions 5.3 through 8.x need stdc++fs for std::filesystem
		}

		defines {
			"KO_PLATFORM_LINUX"
		}

	filter "configurations:Debug"
		defines "KO_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "KO_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "KO_DIST"
		runtime "Release"
		optimize "on"
