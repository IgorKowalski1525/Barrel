workspace "Barrel"
	architecture "x64"
	startproject "Sandbox"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Barrel"
	location "Barrel"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "brpch.h"
	pchsource "Barrel/src/brpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}
	
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"BR_PLATFORM_WINDOWS",
			"BR_BUILD_DLL"
		}
		buildoptions
		{
			"/utf-8"
		}
			postbuildcommands
		{
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/")
		}
		

	filter "configurations:Debug"
		defines "BR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BR_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	buildoptions
		{
			"/utf-8"
		}
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"Barrel/vendor/spdlog/include",
		"Barrel/src"
	}

	links
	{
		"Barrel"
	}
	
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"BR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BR_DIST"
		optimize "On"