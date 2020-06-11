workspace "Juno"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root
IncludeDir = {}
IncludeDir["GLFW"] = "Juno/vendor/GLFW/include"
IncludeDir["Glad"] = "Juno/vendor/Glad/include"
IncludeDir["ImGui"] = "Juno/vendor/imgui"
IncludeDir["glm"] = "Juno/vendor/glm"
IncludeDir["stb_image"] = "Juno/vendor/stb_image"

group "Dependencies"
	include "Juno/vendor/GLFW"
	include "Juno/vendor/Glad"
	include "Juno/vendor/imgui"
group ""

project "Juno"
	location "Juno"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "junopch.h"
	pchsource "Juno/src/junopch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
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
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"JUNO_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		links
		{
			"opengl32.lib"
		}

	filter "system:linux"
		pic "on"

		links
		{
			"Xrandr",
			"Xi",
			"GLEW",
			"GLU",
			"GL",
			"X11",
			"pthread",
			"d1"
		}

	filter "configurations:Debug"
		defines "JUNO_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "JUNO_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "JUNO_DIST"
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
		"Juno/vendor/spdlog/include",
		"Juno/src",
		"Juno/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Juno"
	}

	filter "system:windows"
		systemversion "latest"

	filter "system:linux"

		links
		{
			"Xrandr",
			"Xi",
			"GLEW",
			"GLU",
			"GL",
			"X11",
			"pthread",
			"d1"
		}

	filter "configurations:Debug"
		defines "JUNO_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "JUNO_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "JUNO_DIST"
		runtime "Release"
		optimize "on"

project "Persephone"
	location "Persephone"
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
		"Juno/vendor/spdlog/include",
		"Juno/src",
		"Juno/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Juno"
	}

	filter "system:windows"
		systemversion "latest"

	filter "system:linux"

		links
		{
			"Xrandr",
			"Xi",
			"GLEW",
			"GLU",
			"GL",
			"X11",
			"pthread",
			"d1"
		}

	filter "configurations:Debug"
		defines "JUNO_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "JUNO_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "JUNO_DIST"
		runtime "Release"
		optimize "on"