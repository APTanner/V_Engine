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
Includes["GLAD"] = "V_Engine/lib/GLAD"
Includes["imgui"] = "V_Engine/lib/imgui"
Includes["glm"] = "V_Engine/lib/glm"

include "V_Engine/lib/GLFW"
include "V_Engine/lib/GLAD"
include "V_Engine/lib/imgui"

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
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/lib/glm/glm/**.hpp",
        "%{prj.name}/lib/glm/glm/**.inl"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{Includes.Simple_Logger}/include",
        "%{Includes.GLFW}/include",
        "%{Includes.GLAD}/include",
        "%{Includes.imgui}",
        "%{Includes.glm}"
    }

    links {
        "GLFW",
        "GLAD",
        "opengl32.lib",
        "dwmapi.lib",
        "imgui",
    }

    cppdialect "C++17"
    systemversion "latest"
	staticruntime "On"

    defines "IMGUI_IMPL_OPENGL_LOADER_CUSTOM"

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"
    filter "configurations:SeaTrials"
        defines "SEA_TRIALS"
        optimize "On"
    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"

