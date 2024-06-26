project "Persephone"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp",
	}

	includedirs
	{
		"%{wks.location}/Juno/vendor/spdlog/include",
		"%{wks.location}/Juno/src",
		"%{wks.location}/Juno/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.ImGuizmo}"
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
			"yaml-cpp",
		}

		defines
		{
			"JUNO_PLATFORM_LINUX"
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
