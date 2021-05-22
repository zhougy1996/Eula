workspace "Eula"
    configurations { "Debug", "Release", "Dist" }
    platforms { "Win64" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Eula"
    location "Eula"
    kind "SharedLib"
    language "C++"
    files {
        "%{prj.location}/src/**.h", 
        "%{prj.location}/src/**.cpp"
        }

    includedirs{
        "Eula/src",
        "Eula/vendor/spdlog/include"
    }

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    configuration "windows"
        cppdialect "C++17"
        staticruntime "on"
        systemversion "latest"
        defines {
            "EULA_PLATFORM_WINDOWS",
            "EULA_BUILD_DLL"
        }
        postbuildcommands {
            --Copy Eula.dll into Sandbox
            ("{COPY} %{cfg.buildtarget.relpath} %{wks.location}bin/" .. outputdir .. "/Sandbox")
        }

    filter { "configurations:Debug" }
        defines { "EULA_DEBUG" }
        symbols "On"

    filter { "configurations:Release" }
         defines { "EULA_RELEASE" }
         optimize "On"

    filter { "configurations:Dist" }
         defines { "EULA_DIST" }
         optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    files {
        "%{prj.location}/src/**.h", 
        "%{prj.location}/src/**.cpp"
        }

    links{
        "Eula"
    }

    includedirs{
        "Eula/src",
        "Eula/vendor/spdlog/include"
    }

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    configuration "windows"
        cppdialect "C++17"
        staticruntime "on"
        systemversion "latest"
        defines {
            "EULA_PLATFORM_WINDOWS"
        }

    filter { "configurations:Debug" }
        defines { "EULA_DEBUG" }
        symbols "On"

    filter { "configurations:Release" }
         defines { "EULA_RELEASE" }
         optimize "On"

    filter { "configurations:Dist" }
         defines { "EULA_DIST" }
         optimize "On"

