include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Juno"
	architecture "x64"
	startproject "Persephone"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Juno/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Juno/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Juno/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Juno/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Juno/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Juno/vendor/EnTT/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Juno/vendor/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "%{wks.location}/Juno/vendor/ImGuizmo"

group "Dependencies"
	include "vendor/premake"
	include "Juno/vendor/GLFW"
	include "Juno/vendor/Glad"
	include "Juno/vendor/imgui"
	include "Juno/vendor/yaml-cpp"
group ""

include "Juno"
include "Sandbox"
include "Persephone"
