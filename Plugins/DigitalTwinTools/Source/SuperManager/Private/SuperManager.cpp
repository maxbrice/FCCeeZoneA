// Copyright Epic Games, Inc. All Rights Reserved.

#include "SuperManager.h"
#include "ContentBrowserModule.h"
#include "DebugHeader.h"
#include "EditorAssetLibrary.h"
#include "ObjectTools.h"
#include "CustomStyle/SuperManagerStyle.h"
#include "CustomUICommand/SuperManagerUICommands.h"
#include "AssetToolsModule.h"
#include "AssetViewUtils.h"

#include "DesktopPlatformModule.h"
#include "LevelEditorSubsystem.h"



#include "Editor.h"
//#include "DatasmithImportOptions.h"
#include "ISceneOutliner.h"
#include "LevelEditor.h"
#include "SceneOutlinerModule.h"
#include "Selection.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetRegistry/IAssetRegistry.h"
#include "CustomOutlinerColumn/OutlinerSelectionColumn.h"
#include "Engine/World.h"
#include "Misc/MessageDialog.h"
#include "SlateWidgets/AdvanceDeletionWidget.h"
#include "Subsystems/EditorActorSubsystem.h"


#define LOCTEXT_NAMESPACE "FSuperManagerModule"

class ULevelEditorSubsystem;

void FSuperManagerModule::StartupModule()
{
	FSuperManagerStyle::InitializeIcons();
	
	InitCBMenuExtention();

	RegisterAdvanceDeletionTab();

	FSuperManagerUICommands::Register();

	InitCustomUICommands();

	InitLevelEditorExtention();

	InitCustomSelectionEvent();
	
	InitSceneOutlinerColumnExtension();
	
}

#pragma region ContentBrowserMenuExtention

void FSuperManagerModule::InitCBMenuExtention()
{
	FContentBrowserModule& ContentBrowserModule =
		FModuleManager::LoadModuleChecked<FContentBrowserModule>(TEXT("ContentBrowser"));

	//Get hold of all the menu extenders
	TArray<FContentBrowserMenuExtender_SelectedPaths>& ContentBrowserModuleMenuExtenders =
		ContentBrowserModule.GetAllPathViewContextMenuExtenders();

	/*FContentBrowserMenuExtender_SelectedPaths CustomCBMenuDelegate;
	CustomCBMenuDelegate.BindRaw(this,&FSuperManagerModule::CustomCBMenuExtender);

	ContentBrowserModuleMenuExtenders.Add(CustomCBMenuDelegate);*/

	//We add custom delete to all the existing delegate
	ContentBrowserModuleMenuExtenders.Add(FContentBrowserMenuExtender_SelectedPaths::
		CreateRaw(this, &FSuperManagerModule::CustomCBMenuExtender));
}

//To define the position for inserting menu entry
TSharedRef<FExtender> FSuperManagerModule::CustomCBMenuExtender(const TArray<FString>& SelectedPaths)
{
	TSharedRef<FExtender> MenuExtender(new FExtender());

	if (SelectedPaths.Num() > 0)
	{
		MenuExtender->AddMenuExtension(FName("Delete"), //Extend hook, position to insert
		                               EExtensionHook::After, //Insert before or after
		                               TSharedPtr<FUICommandList>(), //Custom hot keys 
		                               FMenuExtensionDelegate::CreateRaw(this, &FSuperManagerModule::AddCBMenuEntry)); //Second binding, will define details for this menu entry

		FolderPathsSelected = SelectedPaths;
	}

	return MenuExtender;
}

//Define details for the custom menu entry
void FSuperManagerModule::AddCBMenuEntry(FMenuBuilder& MenuBuilder)
{
	MenuBuilder.AddMenuEntry
	(
		FText::FromString(TEXT("Delete Unused Assets")), //Title text for menu entry
		FText::FromString(TEXT("Safely delete all unused assets under folder")), //Tooltip text
		FSlateIcon(FSuperManagerStyle::GetStyleSetName(),"ContentBrowser.DeleteUnusedAssets"),	//Custom icon
		FExecuteAction::CreateRaw(this, &FSuperManagerModule::OnDeleteUnsuedAssetButtonClicked)
		//The actual function to execute
	);

	MenuBuilder.AddMenuEntry
	(
		FText::FromString(TEXT("Delete Empty Folder")), //Title text for menu entry
		FText::FromString(TEXT("Safely delete all empty folder")), //Tooltip text
		FSlateIcon(FSuperManagerStyle::GetStyleSetName(),"ContentBrowser.DeleteEmptyFolders"),	//Custom icon
		FExecuteAction::CreateRaw(this, &FSuperManagerModule::OnDeleteEmptyFoldersButtonClicked)
		//The actual function to excute
	);

	MenuBuilder.AddMenuEntry
	(
		FText::FromString(TEXT("Advance Deletion")), //Title text for menu entry
		FText::FromString(TEXT("List assets by specific condition in a tab for deleting")), //Tooltip text
		FSlateIcon(FSuperManagerStyle::GetStyleSetName(),"ContentBrowser.AdvanceDeletion"),	//Custom icon
		FExecuteAction::CreateRaw(this,&FSuperManagerModule::OnAdvanceDeletionButtonClicked) //The actual function to excute
	);
}

void FSuperManagerModule::OnDeleteUnsuedAssetButtonClicked()
{
	if(ConstructedDockTab.IsValid())
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("Please close advance deletion tab before this operation"));
		return;
	}
	if (FolderPathsSelected.Num() > 1)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("You can only do this to one folder"));
		return;
	}

	TArray<FString> AssetsPathNames = UEditorAssetLibrary::ListAssets(FolderPathsSelected[0]);

	//Whether there are assets under selected folder
	if (AssetsPathNames.Num() == 0)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("No asset found under selected folder"),false);
		return;
	}

	EAppReturnType::Type ConfirmResult =
		DebugHeader::ShowMsgDialog(EAppMsgType::YesNo,
		                           TEXT("A total of ") + FString::FromInt(AssetsPathNames.Num())
		                           + TEXT(" found.\nWoudle you like to procceed?"),false);

	if (ConfirmResult == EAppReturnType::No) return;


	FixUpRedirectors();

	TArray<FAssetData> UnusedAssetsDataArray;

	for (const FString& AssetPathName : AssetsPathNames)
	{
		//Don't touch root folder
		if (AssetPathName.Contains(TEXT("Developers")) ||
			AssetPathName.Contains(TEXT("Collections")) ||
			AssetPathName.Contains(TEXT("__ExternalActors__")) ||
			AssetPathName.Contains(TEXT("__ExternalObjects__")))
		{
			continue;
		}

		if (!UEditorAssetLibrary::DoesAssetExist(AssetPathName)) continue;

		TArray<FString> AssetReferencers =
			UEditorAssetLibrary::FindPackageReferencersForAsset(AssetPathName);

		if (AssetReferencers.Num() == 0)
		{
			const FAssetData UnusedAssetData = UEditorAssetLibrary::FindAssetData(AssetPathName);
			UnusedAssetsDataArray.Add(UnusedAssetData);
		}
	}

	if (UnusedAssetsDataArray.Num() > 0)
	{
		ObjectTools::DeleteAssets(UnusedAssetsDataArray);
	}
	else
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("No unused asset found under selected folder"),false);
	}
}

void FSuperManagerModule::OnDeleteEmptyFoldersButtonClicked()
{
	if(ConstructedDockTab.IsValid())
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("Please close advance deletion tab before this operation"));
		return;
	}
	
	FixUpRedirectors();
	
	TArray<FString> FolderPathsArray = UEditorAssetLibrary::ListAssets(FolderPathsSelected[0],true,true);
	uint32 Counter = 0;

	FString EmptyFolderPathsNames;
	TArray<FString> EmptyFoldersPathsArray;

	for(const FString& FolderPath:FolderPathsArray)
	{
		if(FolderPath.Contains(TEXT("Developers"))||
		FolderPath.Contains(TEXT("Collections")) ||
		FolderPath.Contains(TEXT("__ExternalActors__")) ||
		FolderPath.Contains(TEXT("__ExternalObjects__")))
		{
			continue;
		}
 
		if(!UEditorAssetLibrary::DoesDirectoryExist(FolderPath)) continue;
 
		if(!UEditorAssetLibrary::DoesDirectoryHaveAssets(FolderPath))
		{
			EmptyFolderPathsNames.Append(FolderPath);
			EmptyFolderPathsNames.Append(TEXT("\n"));
 
			EmptyFoldersPathsArray.Add(FolderPath);
		}		
	}

	if(EmptyFoldersPathsArray.Num()==0)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("No empty folder found under selected folder"),false);
		return;
	}
 
	EAppReturnType::Type ConfirmResult = DebugHeader::ShowMsgDialog(EAppMsgType::OkCancel,
	TEXT("Empty folders found in:\n") + EmptyFolderPathsNames +TEXT("\nWould you like to delete all?"),false);
 
	if(ConfirmResult==EAppReturnType::Cancel) return;
 	
	for(const FString& EmptyFolderPath:EmptyFoldersPathsArray)
	{
		UEditorAssetLibrary::DeleteDirectory(EmptyFolderPath);
		++Counter ;
		DebugHeader::Print(TEXT("Failed to delete " + EmptyFolderPath),FColor::Red);
	}
 
	if(Counter>0)
	{
		DebugHeader::ShowNotifyInfo(TEXT("Successfully deleted ") + FString::FromInt(Counter) + TEXT("folders"));
	}
	
}


void FSuperManagerModule::OnAdvanceDeletionButtonClicked()
{
	FixUpRedirectors();
	FGlobalTabmanager::Get()->TryInvokeTab(FName("AdvanceDeletion"));
}


void FSuperManagerModule::FixUpRedirectors()
{
	IAssetRegistry& AssetRegistry =
		FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry")).Get();

	// Form a filter from the paths
	FARFilter Filter;
	Filter.bRecursivePaths = true;
	Filter.PackagePaths.Emplace("/Game");


	Filter.ClassPaths.Add(UObjectRedirector::StaticClass()->GetClassPathName());

	// Query for a list of assets in the selected paths
	TArray<FAssetData> AssetList;
	AssetRegistry.GetAssets(Filter, AssetList);

	if (AssetList.Num() == 0) return;

	TArray<FString> ObjectPaths;
	for (const FAssetData& Asset : AssetList)
	{
		ObjectPaths.Add(Asset.GetObjectPathString());
	}

	TArray<UObject*> Objects;
	const bool bAllowedToPromptToLoadAssets = true;
	const bool bLoadRedirects = true;

	AssetViewUtils::FLoadAssetsSettings Settings;
	Settings.bFollowRedirectors = false;
	Settings.bAllowCancel = true;

	AssetViewUtils::ELoadAssetsResult Result = AssetViewUtils::LoadAssetsIfNeeded(ObjectPaths, Objects, Settings);

	if (Result != AssetViewUtils::ELoadAssetsResult::Cancelled)
	{
		// Transform Objects array to ObjectRedirectors array
		TArray<UObjectRedirector*> Redirectors;
		for (UObject* Object : Objects)
		{
			Redirectors.Add(CastChecked<UObjectRedirector>(Object));
		}

		// Load the asset tools module
		FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>(TEXT("AssetTools"));
		AssetToolsModule.Get().FixupReferencers(Redirectors);
	}
}

#pragma endregion

#pragma region LevelEditorMenuExtension
 	
void FSuperManagerModule::InitLevelEditorExtention()
{	
	FLevelEditorModule& LevelEditorModule =
	FModuleManager::LoadModuleChecked<FLevelEditorModule>(TEXT("LevelEditor"));

	TSharedRef<FUICommandList> ExistingLevelCommands = LevelEditorModule.GetGlobalLevelEditorActions();
	ExistingLevelCommands->Append(CustomUICommands.ToSharedRef());
 
	TArray<FLevelEditorModule::FLevelViewportMenuExtender_SelectedActors>& LevelEditorMenuExtenders =
	LevelEditorModule.GetAllLevelViewportContextMenuExtenders();
 
	LevelEditorMenuExtenders.Add(FLevelEditorModule::FLevelViewportMenuExtender_SelectedActors::
	CreateRaw(this,&FSuperManagerModule::CustomLevelEditorMenuExtender));
}
 
TSharedRef<FExtender> FSuperManagerModule::CustomLevelEditorMenuExtender(const TSharedRef<FUICommandList> UICommandList, 
const TArray<AActor*> SelectedActors)
{	
	TSharedRef<FExtender> MenuExtender = MakeShareable(new FExtender());
 	
	if(SelectedActors.Num()>0)
	{
		MenuExtender->AddMenuExtension(
			FName("ActorOptions"),
			EExtensionHook::Before,
			UICommandList,
			FMenuExtensionDelegate::CreateRaw(this,&FSuperManagerModule::AddLevelEditorMenuEntry)
			);
	}
 
	return MenuExtender;
}
 
void FSuperManagerModule::AddLevelEditorMenuEntry(FMenuBuilder & MenuBuilder)
{
	MenuBuilder.AddMenuEntry
	(
		FText::FromString(TEXT("Lock Actor Selection")),
		FText::FromString(TEXT("Prevent actor from being selected")),
		FSlateIcon(FSuperManagerStyle::GetStyleSetName(),"LevelEditor.LockSelection"),
		FExecuteAction::CreateRaw(this,&FSuperManagerModule::OnLockActorSelectionButtonClicked)
	);
 
	MenuBuilder.AddMenuEntry
	(
		FText::FromString(TEXT("Unlock All Actor Selection")),
		FText::FromString(TEXT("Remove the selection constraint on all actor")),
		FSlateIcon(FSuperManagerStyle::GetStyleSetName(),"LevelEditor.UnlockSelection"),
		FExecuteAction::CreateRaw(this,&FSuperManagerModule::OnUnlockActorSelectionButtonClicked)
	);

	/*
	MenuBuilder.AddMenuEntry
	(
		FText::FromString(TEXT("Import 3DXML File")),
		FText::FromString(TEXT("Remove the selection constraint on all actor2")),
		FSlateIcon(FSuperManagerStyle::GetStyleSetName(),"LevelEditor.UnlockSelection"),
		FExecuteAction::CreateRaw(this,&FSuperManagerModule::OnImport3DXMLFileButton)
	);
	*/
}
 
void FSuperManagerModule::OnLockActorSelectionButtonClicked()
{
	if(!GetEditorActorSubsystem()) return;
 
	TArray<AActor*> SelectedActors = WeakEditorActorSubsystem->GetSelectedLevelActors();
 
	if(SelectedActors.Num()==0)
	{
		DebugHeader::ShowNotifyInfo(TEXT("No actor selected"));
		return;
	}
 
	FString CurrentLockedActorNames = TEXT("Locked selection for:");
 
	for(AActor* SelectedActor:SelectedActors)
	{
		if(!SelectedActor) continue;
 
		LockActorSelection(SelectedActor);
 
		WeakEditorActorSubsystem->SetActorSelectionState(SelectedActor,false);
 
		CurrentLockedActorNames.Append(TEXT("\n"));
		CurrentLockedActorNames.Append(SelectedActor->GetActorLabel());
	}

	RefreshSceneOutliner();
	
	DebugHeader::ShowNotifyInfo(CurrentLockedActorNames);
}
 
void FSuperManagerModule::OnUnlockActorSelectionButtonClicked()
{
	if(!GetEditorActorSubsystem()) return;
 
	TArray<AActor*> AllActorsInLevel = WeakEditorActorSubsystem->GetAllLevelActors();
	TArray<AActor*> AllLockedActors;
 
	for(AActor* ActorInLevel:AllActorsInLevel)
	{
		if(!ActorInLevel) continue;
 
		if(CheckIsActorSelectionLocked(ActorInLevel))
		{
			AllLockedActors.Add(ActorInLevel);
		}
	}
 
	if(AllLockedActors.Num()==0)
	{
		DebugHeader::ShowNotifyInfo(TEXT("No selection locked actor currently"));
		return;
	}
 
	FString UnlockedActorNames = TEXT("Lifted selection constraint for:");
 
	for(AActor* LockedActor:AllLockedActors)
	{
		UnlockActorSelection(LockedActor);
 
		UnlockedActorNames.Append(TEXT("\n"));
		UnlockedActorNames.Append(LockedActor->GetActorLabel());
	}

	RefreshSceneOutliner();
	
	DebugHeader::ShowNotifyInfo(UnlockedActorNames);
}

/*
void FSuperManagerModule::OnImport3DXMLFileButton() const
{
	// Open file dialog to select 3DXML file
	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	if (!DesktopPlatform) return;

	TArray<FString> OutFiles;
	bool bFileSelected = DesktopPlatform->OpenFileDialog(
		FSlateApplication::Get().FindBestParentWindowHandleForDialogs(nullptr),
		TEXT("Select 3DXML File"),
		FPaths::ProjectContentDir(),
		TEXT(""),
		TEXT("3DXML Files (*.3dxml)|*.3dxml"),
		EFileDialogFlags::None,
		OutFiles
	);

	if (!bFileSelected || OutFiles.Num() == 0) return;
	FString FilePath = OutFiles[0];

	// Create Imports directory if it doesn't exist
	FString ImportDir = FPaths::Combine(FPaths::ProjectContentDir(), TEXT("Imports"));
	IFileManager::Get().MakeDirectory(*ImportDir, true);

	// Generate unique level name based on 3DXML filename
	FString LevelName = FPaths::GetBaseFilename(FilePath);
	const FString PackagePath = FString::Printf(TEXT("/Game/Imports/%s"), *LevelName);
	FString SubLevelPath = PackagePath;
	DebugHeader::ShowNotifyInfo(SubLevelPath);

	// Create a new level
	// Set as active level
	//GEditor->GetEditorSubsystem<ULevelEditorSubsystem>()->NewLevel(TEXT("/Game/Imports/Test"), true);
	
}
*/


	


#pragma endregion

#pragma region CustomEditorTab
	
void FSuperManagerModule::RegisterAdvanceDeletionTab()
{
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(FName("AdvanceDeletion"),
	FOnSpawnTab::CreateRaw(this,&FSuperManagerModule::OnSpawnAdvanceDeletionTab))
	.SetDisplayName(FText::FromString(TEXT("Advance Deletion")))
	 .SetIcon(FSlateIcon(FSuperManagerStyle::GetStyleSetName(),"ContentBrowser.AdvanceDeletion"));
}



TSharedRef<SDockTab> FSuperManagerModule::OnSpawnAdvanceDeletionTab(const FSpawnTabArgs &SpawnTabArgs)
{	
	if(FolderPathsSelected.Num()==0) return SNew(SDockTab).TabRole(ETabRole::NomadTab);
 
	ConstructedDockTab = 
		SNew(SDockTab).TabRole(ETabRole::NomadTab)
		 [
			 SNew(SAdvanceDeletionTab)
		 	.AssetsDataToStore(GetAllAssetDataUnderSelectedFolder())
		 	.CurrentSelectedFolder(FolderPathsSelected[0])
		 ];
	ConstructedDockTab->SetOnTabClosed(
		 SDockTab::FOnTabClosedCallback::CreateRaw(this,&FSuperManagerModule::OnAdvanceDeletionTabClosed));
 
	return ConstructedDockTab.ToSharedRef();
}

TArray<TSharedPtr<FAssetData>> FSuperManagerModule::GetAllAssetDataUnderSelectedFolder()
{
	TArray< TSharedPtr <FAssetData> > AvaiableAssetsData;
 
	TArray<FString> AssetsPathNames = UEditorAssetLibrary::ListAssets(FolderPathsSelected[0]);
 
	for(const FString& AssetPathName:AssetsPathNames)
	{
		//Don't touch root folder
		if(AssetPathName.Contains(TEXT("Developers"))||
		AssetPathName.Contains(TEXT("Collections")) ||
		AssetPathName.Contains(TEXT("__ExternalActors__")) ||
		AssetPathName.Contains(TEXT("__ExternalObjects__")))
		{
			continue;
		}
 
		if(!UEditorAssetLibrary::DoesAssetExist(AssetPathName)) continue;
 
		const FAssetData Data = UEditorAssetLibrary::FindAssetData(AssetPathName);
 
		AvaiableAssetsData.Add(MakeShared<FAssetData>(Data));
	}
 
	return AvaiableAssetsData;
}
void FSuperManagerModule::OnAdvanceDeletionTabClosed(TSharedRef<SDockTab> TabToClose)
{
	if(ConstructedDockTab.IsValid())
	{
		ConstructedDockTab.Reset();
		FolderPathsSelected.Empty();
	}
}
#pragma endregion

#pragma region ProccessDataForAdvanceDeletionTab
 
bool FSuperManagerModule::DeleteSingleAssetForAssetList(const FAssetData & AssetDataToDelete)
{	
	TArray<FAssetData> AssetDataForDeletion;
	AssetDataForDeletion.Add(AssetDataToDelete);
 
	if(ObjectTools::DeleteAssets(AssetDataForDeletion)>0)
	{
		return true;
	}
 
	return false;
}

bool FSuperManagerModule::DeleteMultipleAssetsForAssetList(const TArray<FAssetData>& AssetsToDelete)
{
	if(ObjectTools::DeleteAssets(AssetsToDelete)>0)
	{
		return true;
	}
 
	return false;
}
 
void FSuperManagerModule::ListUnusedAssetsForAssetList(const TArray<TSharedPtr<FAssetData>>& AssetsDataToFilter, 
 TArray<TSharedPtr<FAssetData>>& OutUnusedAssetsData)
{
	OutUnusedAssetsData.Empty();
 
	for(const TSharedPtr<FAssetData>& DataSharedPtr:AssetsDataToFilter)
	{	
		TArray<FString> AssetReferencers =
		UEditorAssetLibrary::FindPackageReferencersForAsset(DataSharedPtr->ObjectPath.ToString());
 
		if(AssetReferencers.Num()==0)
		{
			OutUnusedAssetsData.Add(DataSharedPtr);
		}
	}
}

void FSuperManagerModule::ListSameNameAssetsForAssetList(const TArray<TSharedPtr<FAssetData>>& AssetsDataToFilter, 
 TArray<TSharedPtr<FAssetData>>& OutSameNameAssetsData)
{
	OutSameNameAssetsData.Empty();
 
	//Multimap for supporting finding assets with same name
	TMultiMap<FString, TSharedPtr<FAssetData> > AssetsInfoMultiMap;
 
	for(const TSharedPtr<FAssetData>& DataSharedPtr:AssetsDataToFilter)
	{
		AssetsInfoMultiMap.Emplace(DataSharedPtr->AssetName.ToString(), DataSharedPtr);
	}
 
	for(const TSharedPtr<FAssetData>& DataSharedPtr:AssetsDataToFilter)
	{	
		TArray< TSharedPtr <FAssetData> > OutAssetsData;
		AssetsInfoMultiMap.MultiFind(DataSharedPtr->AssetName.ToString(), OutAssetsData);
 
		if(OutAssetsData.Num()<=1) continue;
 		
		for(const TSharedPtr<FAssetData>& SameNameData:OutAssetsData)
		{
			if(SameNameData.IsValid())
			{
				OutSameNameAssetsData.AddUnique(SameNameData);
			}
		}
	}
}

void FSuperManagerModule::SyncCBToClickedAssetForAssetList(const FString & AssetPathToSync)
{
	TArray<FString> AssetsPathToSync;
	AssetsPathToSync.Add(AssetPathToSync);
 
	UEditorAssetLibrary::SyncBrowserToObjects(AssetsPathToSync);
}
#pragma endregion

#pragma region SelectionLock
 
void FSuperManagerModule::InitCustomSelectionEvent()
{
	USelection* UserSelection = GEditor->GetSelectedActors();
 
	UserSelection->SelectObjectEvent.AddRaw(this,&FSuperManagerModule::OnActorSelected);
}
 
void FSuperManagerModule::OnActorSelected(UObject * SelectedObject)
{
	if(!GetEditorActorSubsystem()) return;
	if(AActor* SelectedActor = Cast<AActor>(SelectedObject))
	{
		if(CheckIsActorSelectionLocked(SelectedActor))
		{
			//Deselect actor right away
			WeakEditorActorSubsystem->SetActorSelectionState(SelectedActor,false);
		}
	}
}
void FSuperManagerModule::LockActorSelection(AActor * ActorToProcess)
{
	if(!ActorToProcess) return;
 	
	if(!ActorToProcess->ActorHasTag(FName("Locked")))
	{
		ActorToProcess->Tags.Add(FName("Locked"));
	}	
}
 
void FSuperManagerModule::UnlockActorSelection(AActor * ActorToProcess)
{
	if(!ActorToProcess) return;
 	
	if(ActorToProcess->ActorHasTag(FName("Locked")))
	{
		ActorToProcess->Tags.Remove(FName("Locked"));
	}
}
 
bool FSuperManagerModule::CheckIsActorSelectionLocked(AActor * ActorToProcess)
{	
	if(!ActorToProcess) return false;
 
	return ActorToProcess->ActorHasTag(FName("Locked"));
}
 
#pragma endregion

#pragma region CustomEditorUICommands
 
void FSuperManagerModule::InitCustomUICommands()
{
	CustomUICommands = MakeShareable(new FUICommandList());
 
	CustomUICommands->MapAction(
		FSuperManagerUICommands::Get().LockActorSelection,
		FExecuteAction::CreateRaw(this,&FSuperManagerModule::OnSelectionLockHotKeyPressed)
	);
 
	CustomUICommands->MapAction(
		FSuperManagerUICommands::Get().UnlockActorSelection,
		FExecuteAction::CreateRaw(this,&FSuperManagerModule::OnUnlockActorSelectionHotKeyPressed)
	);
}
 
void FSuperManagerModule::OnSelectionLockHotKeyPressed()
{
	OnLockActorSelectionButtonClicked();
}
 
void FSuperManagerModule::OnUnlockActorSelectionHotKeyPressed()
{
	OnUnlockActorSelectionButtonClicked();
}

#include "ILevelEditor.h"

void FSuperManagerModule::RefreshSceneOutliner()
{
	FLevelEditorModule& LevelEditorModule =
	FModuleManager::LoadModuleChecked<FLevelEditorModule>(TEXT("LevelEditor"));
 
	TSharedPtr<ISceneOutliner> SceneOutliner = LevelEditorModule.GetFirstLevelEditor()->GetMostRecentlyUsedSceneOutliner();
 
	if(SceneOutliner.IsValid())
	{
		SceneOutliner->FullRefresh();
	}
}

#pragma endregion

#pragma region SceneOutlinerExtension
 
void FSuperManagerModule::InitSceneOutlinerColumnExtension()
{	
	FSceneOutlinerModule& SceneOutlinerModule =
	FModuleManager::LoadModuleChecked<FSceneOutlinerModule>(TEXT("SceneOutliner"));
 
	FSceneOutlinerColumnInfo SelectionLockColumnInfo(
		ESceneOutlinerColumnVisibility::Visible,
		1,
		FCreateSceneOutlinerColumn::CreateRaw(this,&FSuperManagerModule::OnCreateSelectionLockColumn)
	);
 
	SceneOutlinerModule.RegisterDefaultColumnType<FOutlinerSelectionLockColumn>(SelectionLockColumnInfo);
}
 
TSharedRef<ISceneOutlinerColumn> FSuperManagerModule::OnCreateSelectionLockColumn(ISceneOutliner & SceneOutliner)
{
	return MakeShareable(new FOutlinerSelectionLockColumn(SceneOutliner));
}
 
#pragma endregion

void FSuperManagerModule::ProcessLockingForOutliner(AActor * ActorToProcess, bool bShouldLock)
{	
	if(!GetEditorActorSubsystem()) return;
 
	if(bShouldLock)
	{
		LockActorSelection(ActorToProcess);
 
		WeakEditorActorSubsystem->SetActorSelectionState(ActorToProcess,false);
 
		DebugHeader::ShowNotifyInfo(TEXT("Locked selection for:\n") + ActorToProcess->GetActorLabel());
	}
	else
	{
		UnlockActorSelection(ActorToProcess);
 
		DebugHeader::ShowNotifyInfo(TEXT("Removed selection lock for:\n") + ActorToProcess->GetActorLabel());
	}
}

bool FSuperManagerModule::GetEditorActorSubsystem()
{	
	if(!WeakEditorActorSubsystem.IsValid())
	{
		WeakEditorActorSubsystem = GEditor->GetEditorSubsystem<UEditorActorSubsystem>();
	}
 
	return WeakEditorActorSubsystem.IsValid();
}

void FSuperManagerModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(FName("AdvanceDeletion"));

	FSuperManagerStyle::ShutDown();

	FSuperManagerUICommands::Unregister();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FSuperManagerModule, SuperManager)
