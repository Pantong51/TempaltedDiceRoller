workspace "DiceRoller"
	architecture "x64"

	configurations
	{
		"Development",
		"Debug",
		"Shipping"
	}

	outputdir = "%{cfg.buildcfg}/%{prj.name}/%{cfg.system}-%{cfg.architecture}"

	flags
	{
		"MultiProcessorCompile"
	}

	group("libs")
		include "Static"
	include "Tests"
