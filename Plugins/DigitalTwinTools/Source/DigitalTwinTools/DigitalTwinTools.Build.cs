// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DigitalTwinTools : ModuleRules
{
	public DigitalTwinTools(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				
					System.IO.Path.GetFullPath(Target.RelativeEnginePath) + "/Source/Editor/Blutility/Private"
				});
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add other public dependencies that you statically link with here ...
				"Core", "Blutility","EditorScriptingUtilities","UMG","Niagara","UnrealEd","AssetTools",
				"ContentBrowser","InputCore","Projects","SceneOutliner", "DesktopPlatform", "Slate", "SlateCore", "EditorStyle",
				"UMG", "Json", "JsonUtilities", "CoreUObject", "Engine",  "EditorFramework",
				"UMGEditor",
				"AssetRegistry", "Projects", "SceneOutliner", "DesktopPlatform", "LevelEditor"

			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"CoreUObject",
				"DesktopPlatform",
				// Editor-specific dependencies
				"UnrealEd",          // For GEditor and basic editor functionality
				"EditorSubsystem",  // Base class for editor subsystems
				"LevelEditor",       // For LevelEditorSubsystem
				"AssetTools",       // For EditorAssetSubsystem
				"ActorPickerMode",   // For EditorActorSubsystem
				"Blutility",        // For Editor Utility functionality
				"UMGEditor",         // For editor-side UMG functionality
				"EditorScriptingUtilities",
				"MeshMergeUtilities",  // For mesh merging
				"MeshUtilitiesCommon", // For mesh utilities
				"MaterialUtilities",  // For material handling
				"StaticMeshEditor",
				"PythonScriptPlugin",
				"Projects",
				"EditorWidgets",
				"EditorFramework",
				"messagelog",
				"AssetRegistry",
				"DerivedDataCache", 
				"AnimationBlueprintLibrary",
				"AnimationBlueprintLibrary",
				"ContentBrowser"
				// Add any other editor-only modules you need
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
