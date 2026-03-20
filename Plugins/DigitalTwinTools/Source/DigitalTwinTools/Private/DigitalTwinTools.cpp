#include "DigitalTwinTools.h"

#include "LevelEditor.h"
#include "DigitalTwinToolsFunctionLibrary.h"

#define LOCTEXT_NAMESPACE "FDigitalTwinToolsModule"

void FDigitalTwinToolsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	UE_LOG(LogTemp, Warning, TEXT("Digital Twin Module Loaded"));
	
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	const TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());

	MenuExtender->AddMenuBarExtension(
		"Help",
		EExtensionHook::After,
		nullptr,
		FMenuBarExtensionDelegate::CreateRaw(this, &FDigitalTwinToolsModule::AddMenu)
		);
	
	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
}

void FDigitalTwinToolsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

void FDigitalTwinToolsModule::AddMenu(FMenuBarBuilder& MenuBarBuilder)
{
	MenuBarBuilder.AddPullDownMenu(
		FText::FromString("DT Tools"),
		FText::FromString("Digital Twin Tools"),
		FNewMenuDelegate::CreateRaw(this, &FDigitalTwinToolsModule::FillMenu)
		);
}

void FDigitalTwinToolsModule::FillMenu(FMenuBuilder& MenuBuilder)
{
	// Import
	MenuBuilder.BeginSection("ImportSection", LOCTEXT("ImportSectionHeader", "Import"));
	{
		MenuBuilder.AddSubMenu(
			LOCTEXT("Submenu", "Import"),
			LOCTEXT("Submenu", "Import .3dxml and .stp files"),
			FNewMenuDelegate::CreateLambda([](FMenuBuilder& SubMenuBuilder)
			{
				SubMenuBuilder.AddMenuEntry(
				LOCTEXT("Submenu", "Import File"),
				LOCTEXT("Submenu", "Import single .3dxml file"),
				FSlateIcon(),
				FUIAction(FExecuteAction::CreateStatic(&UDigitalTwinToolsFunctionLibrary::ImportSceneFromFile))
				);

				SubMenuBuilder.AddMenuEntry(
					LOCTEXT("Submenu", "Import Folder"),
					LOCTEXT("Submenu", "Import all .3dxml files in the selected folder"),
					FSlateIcon(),
					FUIAction(FExecuteAction::CreateStatic(&UDigitalTwinToolsFunctionLibrary::ImportSceneFromFolder))
				);
			
			}));
	}
	MenuBuilder.EndSection();

	MenuBuilder.BeginSection("MergeSection", LOCTEXT("MergeSectionHeader", "Merge"));
	{
		// Merge under selected
		MenuBuilder.AddMenuEntry( 
		FText::FromString("Merge Under Selected Actor"),
		FText::FromString("Merge SM under selected actors"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateStatic(&UDigitalTwinToolsFunctionLibrary::MergeUnderSelectedActors))
		);

		// Simplify under selected
		MenuBuilder.AddMenuEntry( 
		FText::FromString("Simplify Hierarchy Under Selected Actor"),
		FText::FromString("Delete all the AActors under selected actors"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateStatic(&UDigitalTwinToolsFunctionLibrary::SimplifyUnderSelected))
		);
	}
	MenuBuilder.EndSection();
	
	MenuBuilder.BeginSection("MaterialSection", LOCTEXT("MaterialSectionHeader", "Materials"));
	{
		// Change material based on CSV file
		MenuBuilder.AddMenuEntry( 
		FText::FromString("Change Material based on CSV keywords"),
		FText::FromString("Change the materials of the actors if the label correspond to certain keywords contained in selected CSV file"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateStatic(&UDigitalTwinToolsFunctionLibrary::RunMaterialReplacement))
		);
	}
	MenuBuilder.EndSection();
	
	MenuBuilder.BeginSection("ConsolidateSection", LOCTEXT("ConsolidateSectionHeader", "Consolidate"));
	{
		MenuBuilder.AddMenuEntry( 
		FText::FromString("Log equivalent static meshes"),
		FText::FromString("Print in the log which static meshes are equivalent"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateStatic(&UDigitalTwinToolsFunctionLibrary::LogEquivalentStaticMeshGroups))
		);

		MenuBuilder.AddMenuEntry( 
		FText::FromString("Consolidate equivalent static meshes"),
		FText::FromString("Consolidate static meshes which are equivalent"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateStatic(&UDigitalTwinToolsFunctionLibrary::ConsolidateEquivalentStaticMeshGroups))
		);
	}
	MenuBuilder.EndSection();
	
	MenuBuilder.BeginSection("NaniteSection", LOCTEXT("NaniteSectionHeader", "Nanite"));
	{
		MenuBuilder.AddMenuEntry( 
		FText::FromString("Enable Nanite for StaticMeshes"),
		FText::FromString("Enable Nanite for all eligible StaticMeshes"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateStatic(&UDigitalTwinToolsFunctionLibrary::EnableNaniteOnFolderStaticMeshes))
		);
	}
	MenuBuilder.EndSection();
	
	MenuBuilder.BeginSection("LODsection", LOCTEXT("LODSectionHeader", "LODs"));
	{
		MenuBuilder.AddMenuEntry( 
		FText::FromString("Create LODs for StaticMeshes"),
		FText::FromString("Create LODs for all eligible StaticMeshes"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateStatic(&UDigitalTwinToolsFunctionLibrary::CreateLODS))
		);
	}
	MenuBuilder.EndSection();
	
	MenuBuilder.BeginSection("Materialssection", LOCTEXT("MaterialsectionHeader", "Materials"));
	{
		MenuBuilder.AddMenuEntry( 
		FText::FromString("Separate Materials"),
		FText::FromString("Separate the materials for the selected actors"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateStatic(&UDigitalTwinToolsFunctionLibrary::SeparateColors))
		);
	}
	MenuBuilder.EndSection();

	MenuBuilder.BeginSection("Substitutesection", LOCTEXT("SubstitutesectionHeader", "Substitute"));
	{
		MenuBuilder.AddMenuEntry( 
		FText::FromString("Substitute Actors"),
		FText::FromString("Substitute Actors with selected assets"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateStatic(&UDigitalTwinToolsFunctionLibrary::SubstituteActors))
		);
	}
	MenuBuilder.EndSection();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDigitalTwinToolsModule, DigitalTwinTools)