workspace "V_Engine"
    architecture "x64"

    configurations
    {
        "Debug",
        "SeaTrials",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

Includes = {}
Includes["Simple_Logger"] = "V_Engine/lib/Simple_Logger/Simple_Logger"
Includes["GLFW"] = "V_Engine/lib/GLFW"

include "V_Engine/lib/GLFW"

project "V_Engine"
    location "V_Engine"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir    ("build/" .. outputdir .. "/%{prj.name}")
    
    pchheader "pch.h"
    pchsource "V_Engine/src/pch.cpp"

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{Includes.Simple_Logger}/include",
        "%{Includes.GLFW}/include"
    }

    links {
        "GLFW",
        "opengl32.lib"
    }

    cppdialect "C++17"
    systemversion "latest"
	staticruntime "On"

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"
    filter "configurations:SeaTrials"
        defines "SEA_TRIALS"
        optimize "On"
    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"

