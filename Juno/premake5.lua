project "Juno"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "junopch.h"
	pchsource "src/junopch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp",
		"vendor/stb_image/**.h",
		"vendor/stb_image/**.cpp",
		"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl",
		"vendor/ImGuizmo/ImGuizmo.h",
		"vendor/ImGuizmo/ImGuizmo.cpp"
	}

	defines
	{
        "_CRT_SECURE_NO_WARNINGS",
        "GLFW_INCLUDE_NONE",
		"_SILENCE_CXX17_RESULT_OF_DEPRECATION_WARNING"
	}

	includedirs
	{
		"src",
		"vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.yaml_cpp}",
		"%{IncludeDir.ImGuizmo}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"yaml-cpp"
	}

	filter "files:vendor/ImGuizmo/**.cpp"
		flags { "NoPCH" }

	filter "system:windows"
		systemversion "latest"

		removefiles { "**/Linux/**" }

		links 
		{
        	"opengl32.lib"
		}

		defines
		{
		}

	filter "system:linux"
		removefiles { "src/Platform/Windows/WindowsPlatformUtils.cpp" }

		defines
		{
			"JUNO_PLATFORM_LINUX",
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
