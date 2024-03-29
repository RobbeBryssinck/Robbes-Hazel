workspace "RobbEngine"
  architecture "x64"
  startproject "Sandbox"

  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "RobbEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "RobbEngine/vendor/Glad/include"
IncludeDir["imgui"] = "RobbEngine/vendor/imgui"
IncludeDir["glm"] = "RobbEngine/vendor/glm"

group "Dependencies"
  include "RobbEngine/vendor/GLFW"
  include "RobbEngine/vendor/Glad"
  include "RobbEngine/vendor/imgui"

group ""

project "RobbEngine"
  location "RobbEngine"
  kind "StaticLib"
  language "C++"
  cppdialect "C++17"
  staticruntime "on"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  pchheader "repch.h"
  pchsource "RobbEngine/src/repch.cpp"

  files
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp",
    "%{prj.name}/vendor/glm/glm/**.hpp",
    "%{prj.name}/vendor/glm/glm/**.inl",
  }

  defines
  {
        "_CRT_SECURE_NO_WARNINGS"
  }

  includedirs
  {
    "%{prj.name}/src",
    "%{prj.name}/vendor/spdlog/include",
    "%{IncludeDir.GLFW}",
    "%{IncludeDir.Glad}",
    "%{IncludeDir.imgui}",
    "%{IncludeDir.glm}"
  }

  links 
  { 
    "GLFW",
    "Glad",
    "imgui",
    "opengl32.lib"
  }

  filter "system:windows"
    systemversion "latest"

    defines
    {
      "RE_PLATFORM_WINDOWS",
      "RE_BUILD_DLL",
      "GLFW_INCLUDE_NONE"
    }

  filter "configurations:Debug"
    defines "RE_DEBUG"
    runtime "Debug"
    symbols "on"

  filter "configurations:Release"
    defines "RE_RELEASE"
    runtime "Release"
    optimize "on"

  filter "configurations:Dist"
    defines "RE_DIST"
    runtime "Release"
    optimize "on"

project "Sandbox"
  location "Sandbox"
  kind "ConsoleApp"
  language "C++"
  cppdialect "C++17"
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
    "RobbEngine/vendor/spdlog/include",
    "RobbEngine/src",
    "RobbEngine/vendor",
    "%{IncludeDir.glm}"
  }

  links
  {
    "RobbEngine"
  }

  filter "system:windows"
    systemversion "latest"

    defines
    {
      "RE_PLATFORM_WINDOWS"
    }

  filter "configurations:Debug"
    defines "RE_DEBUG"
    runtime "Debug"
    symbols "on"

  filter "configurations:Release"
    defines "RE_RELEASE"
    runtime "Release"
    optimize "on"

  filter "configurations:Dist"
    defines "RE_DIST"
    runtime "Release"
    optimize "on"