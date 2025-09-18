// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class JobSimulation : ModuleRules
{
	public JobSimulation(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"UMG",
			"SlateCore",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
			"HeadMountedDisplay",
			"SteamVR",
			"OpenXR",
			"XRBase",
			"GeometryScriptingCore",
			"ModelingComponents",
			"DynamicMesh"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
