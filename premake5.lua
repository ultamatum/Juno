workspace "Oak"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-${cfg.architecture}"
	
project "Oak"
	location "Oak"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"OK_PLATFORM_WINDOWS",
			"OK_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
		}

	filter "configurations.Debug"
		defines "OK_DEBUG"
		symbols "On"
		
	filter "configurations.Release"
		defines "OK_RELEASE"
		optimize "On"
		
	filter "configurations.Dist"
		defines "OK_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

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
		symbols "On"
		
	filter "configurations.Release"
		defines "OK_RELEASE"
		optimize "On"
		
	filter "configurations.Dist"
		defines "OK_DIST"
		optimize "On"