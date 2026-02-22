workspace "ClayPOT"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }
    startproject "Editor"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "ClayPOT/vendor/GLFW/include"
IncludeDir["glad"] = "ClayPOT/vendor/glad/include"

include "ClayPOT/vendor/GLFW"
include "ClayPOT/vendor/glad"

project "ClayPOT"
    location "ClayPOT"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "cph.h"
    pchsource "ClayPOT/src/cph.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glad}"
    }

	links
	{
		"GLFW",
		"glad",
		"opengl32.lib"
	}

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions { "/utf-8" }

        defines {
            "CP_PLATFORM_WINDOWS",
            "CP_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
        }

		postbuildcommands 
		{
			("echo Creating Editor folder if it does not exist..."),
			("if not exist \"%{wks.location}/bin/" .. outputdir .. "/Editor/\" mkdir \"%{wks.location}/bin/" .. outputdir .. "/Editor/\""),
			("echo Copying ClayPOT.dll to Editor..."),
			("{COPY} \"%{cfg.buildtarget.abspath}\" \"%{wks.location}/bin/" .. outputdir .. "/Editor/\"")
		}


    filter "configurations:Debug"
        defines "CP_DEBUG"
		defines "CP_ENABLE_ASSERT"
        symbols "On"

    filter "configurations:Release"
        defines "CP_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "CP_DIST"
        optimize "On"

    filter {}

project "Editor"
    location "Editor"
    kind "ConsoleApp"
    language "C++"
    buildoptions { "/utf-8" }

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "ClayPOT/vendor/spdlog/include",
        "ClayPOT/src"
    }

    links { "ClayPOT" }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        defines "CP_PLATFORM_WINDOWS"

    filter "configurations:Debug"
        defines "CP_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "CP_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "CP_DIST"
        optimize "On"

    filter {}
