// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CCC_Vigivalovo : ModuleRules
{
	public CCC_Vigivalovo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"CCC_Vigivalovo",
			"CCC_Vigivalovo/Variant_Horror",
			"CCC_Vigivalovo/Variant_Horror/UI",
			"CCC_Vigivalovo/Variant_Shooter",
			"CCC_Vigivalovo/Variant_Shooter/AI",
			"CCC_Vigivalovo/Variant_Shooter/UI",
			"CCC_Vigivalovo/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
