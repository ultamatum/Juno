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
IncludeDir["glm"] = "Oak/vendor/glm"

group "Dependencies"
	include "Oak/vendor/GLFW"
	include "Oak/vendor/Glad"
	include "Oak/vendor/imgui"

group ""

project "Oak"
	location "Oak"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "okpch.h"
	pchsource "Oak/src/okpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"OK_PLATFORM_WINDOWS",
			"OK_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "OK_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "OK_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "OK_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Oak/vendor/spdlog/include",
		"Oak/src",
		"Oak/vendor",
		"{IncludeDir.glm}"
	}

	links
	{
		"Oak"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"OK_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "OK_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "OK_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "OK_DIST"
		runtime "Release"
		optimize "on"
