// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System;
using System.IO;
using System.Collections.Generic;

public class SuperManager : ModuleRules
{
	public SuperManager(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);


		PrivateIncludePaths.AddRange(
			new string[]
			{
				System.IO.Path.GetFullPath(Target.RelativeEnginePath) + "/Source/Editor/Blutility/Private"
			});
        /*                                                              
		PrivateIncludePaths.AddRange(
			new string[] {System.IO.Path.GetFullPath(Target.RelativeEnginePath) + "/Plugins/Enterprise/DatasmithCADImporter" 
				// ... add other private include paths required here ...
			}
			
			);
		*/	
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core","Blutility","EditorScriptingUtilities","UMG","UnrealEd","AssetTools",
				"ContentBrowser","InputCore","Projects","SceneOutliner", "DesktopPlatform", "Slate", "SlateCore", "EditorStyle",
				"UMG", "Json", "JsonUtilities", "CoreUObject", "Engine",  "EditorFramework",
				 "UMGEditor",
				"AssetRegistry", "Projects", "SceneOutliner", "DesktopPlatform", "LevelEditor"
				
				
				
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject", "Engine",
				"Slate",
				"SlateCore",
				"CoreUObject",
				"UnrealEd",
				"LevelEditor",
				"EditorWidgets",
				"EditorSubsystem",
				"EditorFramework",
				"DesktopPlatform",
				"AssetRegistry",
				"Projects",
				"messagelog",
				"AssetRegistry", "DerivedDataCache", "AnimationBlueprintLibrary", "AnimationBlueprintLibrary",
				"ContentBrowser",
				"Projects",
				//"DatasmithTranslator",
				
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
		
		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.Add("EditorScriptingUtilities");
		}
	}
}
