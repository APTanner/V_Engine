workspace "V_Engine"
    architecture "x64"

    configurations
    {
        "Debug",
        "SeaTrials",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-{cfg.architecture}"

project "V_Engine"
    location "V_Engine"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir    ("build/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/lib/fOutput/include"
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

