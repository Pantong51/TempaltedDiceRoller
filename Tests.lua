project "Tests"
	location "Tests"
	kind "ConsoleApp"
	language "c++"
	staticruntime "on"

	floatingpoint "Fast"
	exceptionhandling "Off"
	vectorextensions "SSE2"

	targetdir("$(SolutionDir)Builds/bin/" .. outputdir)
	objdir("$(SolutionDir)Builds/bin-int/" .. outputdir)

	files
	{
		"Tests/**.h",
		"Tests/**.cpp",
		"Tests/**.hpp"
	}

	includedirs
	{
		"$(SolutionDir)%{prj.name}",
		"$(SolutionDir)Static/",
	}

	buildoptions
	{
		"/GT",
		"/Oi",
		"/GR-",
		"/Ot",
		"/Ob2"
	}

	links
	{
		"Static"
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