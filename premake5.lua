workspace "V_Engine"
    architecture "x64"

    configurations
    {
        "Debug",
        "SeaTrials",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

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
        "%{prj.name}/lib/Simple_Logger/Simple_Logger/include"
    }

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"
    filter "configurations:SeaTrials"
        defines "SEATRIALS"
        optimize "On"
    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"

