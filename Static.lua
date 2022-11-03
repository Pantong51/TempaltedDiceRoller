project "Static"
	location "Static"
	kind "StaticLib"
	language "c++"
	staticruntime "on"

	floatingpoint "Fast"
	exceptionhandling "Off"
	vectorextensions "SSE2"

	targetdir("$(SolutionDir)Builds/bin/" .. outputdir)
	objdir("$(SolutionDir)Builds/bin-int/" .. outputdir)

	files
	{
		"Static/**.h",
		"Static/**.cpp",
		"Static/**.hpp"
	}

	includedirs
	{
		"$(SolutionDir)%{prj.name}/"
	}

	buildoptions
	{
		"/GT",
		"/Oi",
		"/GR-",
		"/Ot",
		"/Ob2"
	}

	filter "system:windows"
		cppdialect "C++20"
		systemversion "latest"

	filter "configurations:Development"
		runtime "Debug"
		symbols "On"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"
		optimize "On"

	filter "configurations:Shipping"
		runtime "Release"
		optimize "On"