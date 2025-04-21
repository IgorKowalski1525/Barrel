workspace "Barrel"
	architecture "x64"
	buildoptions{"/utf-8"}
	startproject "Sandbox"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Barrel/vendor/GLFW/include"
IncludeDir["Glad"] = "Barrel/vendor/Glad/include"
IncludeDir["ImGui"] = "Barrel/vendor/imgui"
IncludeDir["glm"] = "Barrel/vendor/glm"

include "Barrel/vendor/GLFW"
include "Barrel/vendor/Glad"
include "Barrel/vendor/imgui"

project "Barrel"
	location "Barrel"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "brpch.h"
	pchsource "Barrel/src/brpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
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
		"opengl32.lib",
		"ImGui"
	}
	filter "system:windows"
		systemversion "latest"

		defines
		{
			"BR_PLATFORM_WINDOWS",
			"BR_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "BR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BR_RELEASE"
		runtime "Release"
		optimize "on"	

	filter "configurations:Dist"
		defines "BR_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Barrel/vendor/spdlog/include",
		"Barrel/src",
		"Barrel/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Barrel"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"BR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BR_RELEASE"
		runtime "Release"
		optimize "on"
		
	filter "configurations:Dist"
		defines "BR_DIST"
		runtime "Release"
		optimize "on"
		