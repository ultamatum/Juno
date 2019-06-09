workspace "Oak"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root
IncludeDir = {}
IncludeDir["GLFW"] = "Oak/vendor/GLFW/include"
IncludeDir["Glad"] = "Oak/vendor/Glad/include"
IncludeDir["ImGui"] = "Oak/vendor/imgui"

include "Oak/vendor/GLFW"
include "Oak/vendor/Glad"
include "Oak/vendor/imgui"

project "Oak"
	location "Oak"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "okpch.h"
	pchsource "Oak/src/okpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"OK_PLATFORM_WINDOWS",
			"OK_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations.Debug"
		defines "OK_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations.Release"
		defines "OK_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations.Dist"
		defines "OK_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Oak/vendor/spdlog/include",
		"Oak/src"
	}

	links
	{
		"Oak"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"OK_PLATFORM_WINDOWS",
		}

	filter "configurations.Debug"
		defines "OK_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations.Release"
		defines "OK_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations.Dist"
		defines "OK_DIST"
		buildoptions "/MD"
		optimize "On"
