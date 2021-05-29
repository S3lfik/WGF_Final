// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WGF_Final : ModuleRules
{
	public WGF_Final(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
