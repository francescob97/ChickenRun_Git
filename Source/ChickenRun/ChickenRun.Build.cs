// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ChickenRun : ModuleRules
{
	public ChickenRun(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "EnhancedInput", "UMG" });
	}
}
