// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class BattleBlaster : ModuleRules
{
	public BattleBlaster(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		// Workaround for Xcode 16.x: its clang falsely flags lambda init-captures in UE 5.8 engine
		// headers as -Wshadow errors. Skip the engine's shared PCH (built with warnings-as-errors)
		// and compile those headers under this module's relaxed setting instead.
		// Safe to remove once on the Xcode version UE 5.8 expects (26.x).
		if (Target.Platform == UnrealTargetPlatform.Mac)
		{
			PCHUsage = PCHUsageMode.NoSharedPCHs;
			CppCompileWarningSettings.ShadowVariableWarningLevel = WarningLevel.Warning;
		}

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
