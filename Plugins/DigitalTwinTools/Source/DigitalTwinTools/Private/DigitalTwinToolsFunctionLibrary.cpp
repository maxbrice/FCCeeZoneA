#include "DigitalTwinToolsFunctionLibrary.h"

#include "Engine/World.h"
#include "IDesktopPlatform.h"
#include "ScopedTransaction.h"
#include "EditorAssetLibrary.h"
#include "IPythonScriptPlugin.h"
#include "ContentBrowserModule.h"
#include "LevelEditorSubsystem.h"
#include "DesktopPlatformModule.h"
#include "Engine/StaticMeshActor.h"
#include "IContentBrowserSingleton.h"
#include "Interfaces/IPluginManager.h"
#include "StaticMeshEditorSubsystem.h"
#include "Serialization/Csv/CsvParser.h"
#include "Subsystems/EditorActorSubsystem.h"
#include "Subsystems/EditorAssetSubsystem.h"
#include "StaticMeshEditorSubsystemHelpers.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Misc/MapErrors.h"
#include "UObject/SavePackage.h"


#define LOCTEXT_NAMESPACE "DigitalTwinTools"

// Helper function to generate the unique actor label
FString UDigitalTwinToolsFunctionLibrary::GetUniqueActorLabel(const FString& BaseName)
{
	FString UniqueName = BaseName;
	int32 Suffix = 0;
	while (FindObject<AActor>(GetTransientPackage(), *UniqueName))
	{
		UniqueName = FString::Printf(TEXT("%s_%d"), *BaseName, Suffix);
		Suffix++;
	}
	return UniqueName;
}

// Helper function to get the merged folder path based on the current level
FString UDigitalTwinToolsFunctionLibrary::GetMergedFolderPath(ULevel* CurrentLevel)
{
	FString LevelPath = CurrentLevel->GetPathName();
	TArray<FString> PathElements;
	LevelPath.ParseIntoArray(PathElements, TEXT("/"));
    
	if (PathElements.Num() >= 2)
	{
		// Remove the last element (the level name)
		PathElements.Pop();
		
		return TEXT("/") + FString::Join(PathElements, TEXT("/")) + TEXT("/Merged");
	}
	
	return TEXT("/Game/Merged");
}

// Helper function to merge static mesh actors
AStaticMeshActor* UDigitalTwinToolsFunctionLibrary::MergeStaticMeshActorsForSelection(
	const TArray<AStaticMeshActor*>& StaticMeshActors,
	const FString& MergedFolderPath,
	const FString& ActorLabel,
	UStaticMeshEditorSubsystem* StaticMeshEditorSubsystem)
{
	FString Name = GetUniqueActorLabel(TEXT("MG_" + ActorLabel.Left(12)));

	// Options for merging static meshes
	FMergeStaticMeshActorsOptions Options;
	Options.NewActorLabel = Name;
	Options.BasePackageName = MergedFolderPath + TEXT("/") + Name;
	Options.bDestroySourceActors = true;
	Options.bSpawnMergedActor = true;

	// FMeshMergingSettings
	Options.MeshMergingSettings.bPivotPointAtZero = false;
	Options.MeshMergingSettings.bBakeVertexDataToMesh = false;
	Options.MeshMergingSettings.bComputedLightMapResolution = false;

	AStaticMeshActor* MergedActor = nullptr;

	if (StaticMeshEditorSubsystem->MergeStaticMeshActors(StaticMeshActors, Options, MergedActor))
	{
		MergedActor->SetMobility(EComponentMobility::Movable);
		return MergedActor;
	}

	UE_LOG(LogTemp, Warning, TEXT("Merge Actors Failed."));
	return nullptr;
}

FString UDigitalTwinToolsFunctionLibrary::OpenFileDialog()
{
	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	if (!DesktopPlatform) return TEXT("");

	TArray<FString> OutFiles;

	bool bSuccess = DesktopPlatform->OpenFileDialog(
	nullptr,
	TEXT("Select a File"),
	FPaths::ProjectContentDir(),       // Default path
	TEXT(""),       // Default file
	TEXT("All Files (*.*)|*.*"),  // File types
	EFileDialogFlags::None,
	OutFiles
	);
	return (bSuccess && OutFiles.Num() > 0) ? OutFiles[0] : TEXT("");
}

// TODO Add optional parameter containing the default path, so that it can have different default paths!
FString UDigitalTwinToolsFunctionLibrary::OpenFolderDialog(const FString& DefaultPath)
{
	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	if (!DesktopPlatform) return TEXT("");

	FString OutFolderName;

	bool bSuccess = DesktopPlatform->OpenDirectoryDialog(
		nullptr,
		TEXT("Select a Folder"),
		FPaths::ProjectContentDir(),
		OutFolderName
	);

	return bSuccess ? OutFolderName : TEXT("");
}

void UDigitalTwinToolsFunctionLibrary::RunPythonImport(const FString& FunctionName, const FString& Path)
{
	// Get plugin directory safely
	TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin("DigitalTwinTools");
	if (!Plugin.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("DigitalTwinTools plugin not found"));
		return;
	}

	const FString PluginDir = Plugin->GetBaseDir();
	const FString PythonDir = FPaths::Combine(PluginDir, TEXT("Python"));

	// Format Python command
	const FString Command = FString::Printf(
		TEXT("import sys\n")
		TEXT("sys.path.append(r'%s')\n")
		TEXT("from python_importer import %s\n")
		TEXT("%s(r'%s')\n"),
		*PythonDir, *FunctionName, *FunctionName, *Path
	);

	IPythonScriptPlugin* PythonPlugin = IPythonScriptPlugin::Get();
	if (PythonPlugin)
	{
		const bool bSuccess = PythonPlugin->ExecPythonCommand(*Command);
		UE_LOG(LogTemp, Log, TEXT("Python script '%s' executed. Success: %d"), *FunctionName, bSuccess);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Python script plugin not available"));
	}
}

void UDigitalTwinToolsFunctionLibrary::GetLevelStaticMeshes(TArray<UStaticMesh*>& OutStaticMeshes)
{
	ULevelEditorSubsystem* LevelEditorSubsystem = GEditor->GetEditorSubsystem<ULevelEditorSubsystem>();
	UEditorActorSubsystem* EditorActorSubsystem = GEditor->GetEditorSubsystem<UEditorActorSubsystem>();
	if (!LevelEditorSubsystem || !EditorActorSubsystem) return;

	ULevel* CurrentLevel = LevelEditorSubsystem->GetCurrentLevel();
	if (!CurrentLevel) return;

	TArray<AActor*> Actors = EditorActorSubsystem->GetAllLevelActors ();

	for (AActor* Actor : Actors)
	{
		if (!Actor) continue;

		if (AStaticMeshActor* StaticMeshActor = Cast<AStaticMeshActor>(Actor))
		{
			if (UStaticMesh* Mesh = StaticMeshActor->GetStaticMeshComponent()->GetStaticMesh())
			{
				OutStaticMeshes.AddUnique(Mesh);
			}
		}
		
	}
}

bool FindExactTransform(
	const TArray<FVector>& A_Vectors,
	const TArray<FVector>& B_Vectors,
	FMatrix& OutTransform
){
	if (A_Vectors.Num() != 3 || B_Vectors.Num() != 3) {
		return false;
	}

	FMatrix A(
		FPlane(A_Vectors[0].X, A_Vectors[1].X, A_Vectors[2].X, 0),
		FPlane(A_Vectors[0].Y, A_Vectors[1].Y, A_Vectors[2].Y, 0),
		FPlane(A_Vectors[0].Z, A_Vectors[1].Z, A_Vectors[2].Z, 0),
		FPlane(0, 0, 0, 1)
	);

	FMatrix B(
		FPlane(B_Vectors[0].X, B_Vectors[1].X, B_Vectors[2].X, 0),
		FPlane(B_Vectors[0].Y, B_Vectors[1].Y, B_Vectors[2].Y, 0),
		FPlane(B_Vectors[0].Z, B_Vectors[1].Z, B_Vectors[2].Z, 0),
		FPlane(0, 0, 0, 1)
	);

	FMatrix AInv = A.Inverse();

	// Check if it is invertible
	if (AInv.Determinant() == 0) {
		return false;
	}
	OutTransform = B * AInv;
	return true;
}

bool UDigitalTwinToolsFunctionLibrary::AreStaticMeshesEquivalent(UStaticMesh* MeshA, UStaticMesh* MeshB)
{
	if (!MeshA || !MeshB) return false;
	if (MeshA == MeshB) return true;
	if (MeshA->GetNumLODs() != MeshB->GetNumLODs()) return false;
	if (MeshA->GetNumSections(0) != MeshB->GetNumSections(0)) return false;

	// Compare materials
	for (int32 i = 0; i < MeshA->GetStaticMaterials().Num(); i++)
	{
		if (MeshA->GetStaticMaterials()[i].MaterialInterface != MeshB->GetStaticMaterials()[i].MaterialInterface)
		{
			return false;
		}
	}

	const FStaticMeshLODResources& LODA = MeshA->GetLODForExport(0);
	const FStaticMeshLODResources& LODB = MeshB->GetLODForExport(0);

	// Compare number of vertices
	if (LODA.VertexBuffers.PositionVertexBuffer.GetNumVertices() != LODB.VertexBuffers.PositionVertexBuffer.GetNumVertices())
	{
		return false;
	}

	/*
	FVector3f a1 = LODA.VertexBuffers.PositionVertexBuffer.VertexPosition(0);
	FVector3f a2 = LODA.VertexBuffers.PositionVertexBuffer.VertexPosition(1);
	FVector3f a3 = LODA.VertexBuffers.PositionVertexBuffer.VertexPosition(2);

	FVector3f b1 = LODB.VertexBuffers.PositionVertexBuffer.VertexPosition(0);
	FVector3f b2 = LODB.VertexBuffers.PositionVertexBuffer.VertexPosition(1);
	FVector3f b3 = LODB.VertexBuffers.PositionVertexBuffer.VertexPosition(2);

	FVector crossA = FVector(a2 - a1).Cross(FVector(a3 - a1));
	FVector crossB = FVector(b2 - b1).Cross(FVector(b3 - b1));
	if (crossA.IsNearlyZero() || crossB.IsNearlyZero())
	{
		return false;
	}
	
	FMatrix OutTransform;
	const TArray<FVector> A_Vectors = {FVector(a1), FVector(a2), FVector(a3)};
	const TArray<FVector> B_Vectors = {FVector(b1), FVector(b2), FVector(b3)};
	if (!FindExactTransform(A_Vectors, B_Vectors, OutTransform))
	{
		return false;
	}
	*/
	
	// Compare the vertices position
	for (uint32 i = 0; i < LODA.VertexBuffers.PositionVertexBuffer.GetNumVertices(); i++)
	{
		// FVector TransformedA = OutTransform.TransformPosition(FVector(LODA.VertexBuffers.PositionVertexBuffer.VertexPosition(i)));
		FVector VertexA = FVector(LODA.VertexBuffers.PositionVertexBuffer.VertexPosition(i));
		FVector VertexB = FVector(LODB.VertexBuffers.PositionVertexBuffer.VertexPosition(i));
        
		if (!VertexA.Equals(VertexB))
		{
			return false;
		}
	}
	
	return true;
}

TArray<TArray<UStaticMesh*>> UDigitalTwinToolsFunctionLibrary::GroupLevelEquivalentMeshes()
{
	TArray<UStaticMesh*> AllMeshes;
	GetLevelStaticMeshes(AllMeshes);

	// Group meshes by vertex count
	TMap<int32, TArray<UStaticMesh*>> VertexCountToMeshes;
	for (UStaticMesh* Mesh : AllMeshes)
	{
		if (!Mesh || Mesh->GetNumLODs() == 0) continue;

		const FStaticMeshLODResources& LOD = Mesh->GetLODForExport(0);
		const int32 VertexCount = LOD.VertexBuffers.PositionVertexBuffer.GetNumVertices();
		VertexCountToMeshes.FindOrAdd(VertexCount).Add(Mesh);
	}

	// Compare meshes within each vertex-count group 
	TArray<TArray<UStaticMesh*>> MeshGroups;
	for (auto& Pair : VertexCountToMeshes)
	{
		const TArray<UStaticMesh*>& MeshesWithSameVertexCount = Pair.Value;
        
		if (MeshesWithSameVertexCount.Num() == 1)
		{
			MeshGroups.Add({ MeshesWithSameVertexCount[0] });
			continue;
		}

		for (UStaticMesh* Mesh : MeshesWithSameVertexCount)
		{
			bool bGrouped = false;
			for (TArray<UStaticMesh*>& Group : MeshGroups)
			{
				if (AreStaticMeshesEquivalent(Group[0], Mesh))
				{
					Group.Add(Mesh);
					bGrouped = true;
					break;
				}
			}
			if (!bGrouped)
			{
				MeshGroups.Add({ Mesh });
			}
		}
	}
	return MeshGroups;
}

void UDigitalTwinToolsFunctionLibrary::ConsolidateEquivalentStaticMeshGroups()
{
	TArray<TArray<UStaticMesh*>> MeshGroups = GroupLevelEquivalentMeshes();

	FScopedSlowTask SlowTask = FScopedSlowTask(MeshGroups.Num(), NSLOCTEXT("DT-SlowTask", "SlowTask", "Processing..."), true);
	SlowTask.MakeDialog(true);
	for (int32 i = 0; i < MeshGroups.Num(); i++)
	{
		SlowTask.EnterProgressFrame(1, FText::Format(NSLOCTEXT("DT-SlowTask", "SlowTask", "Processing... {0} / {1}"), FText::AsNumber(i), FText::AsNumber(MeshGroups.Num())));
		if (MeshGroups[i].Num() > 1)
		{
			UStaticMesh* PrimaryAsset = MeshGroups[i][0];
			
			TArray<UObject*> ObjectsToConsolidate;
			for (int32 j = 1; j < MeshGroups[i].Num(); j++)
			{
				ObjectsToConsolidate.Add(MeshGroups[i][j]);
			}
            
			// Consolidate assets
			UEditorAssetLibrary::ConsolidateAssets(PrimaryAsset, ObjectsToConsolidate);
		}
	}
}

void UDigitalTwinToolsFunctionLibrary::LogEquivalentStaticMeshGroups()
{
    TArray<TArray<UStaticMesh*>> MeshGroups = GroupLevelEquivalentMeshes();

    // Log results
    UE_LOG(LogTemp, Log, TEXT("==== Equivalent Static Mesh Groups ===="));
    int32 g_number = 0;
	int32 total_meshes = 0;
    for (int32 i = 0; i < MeshGroups.Num(); ++i)
    {
        if (MeshGroups[i].Num() > 1)
        {
            UE_LOG(LogTemp, Log, TEXT("-- Group %d --"), g_number++);
            for (UStaticMesh* Mesh : MeshGroups[i])
            {
                UE_LOG(LogTemp, Log, TEXT("  %s"), *Mesh->GetName());
            	total_meshes++;
            }
        }
    }
	UE_LOG(LogTemp, Log, TEXT("Total meshes deleted after consolidation: %d "), total_meshes - g_number);
}

void UDigitalTwinToolsFunctionLibrary::ImportSceneFromFile()
{
	FString FilePath = OpenFileDialog();
	if (FilePath.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("No file selected"));
		return;
	}

	RunPythonImport(TEXT("import_scene_from_file"), FilePath);
}

void UDigitalTwinToolsFunctionLibrary::ImportSceneFromFolder()
{
	FString FolderPath = OpenFolderDialog();
	if (FolderPath.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("No folder selected"));
		return;
	}

	RunPythonImport(TEXT("import_scene_from_folder"), FolderPath);
}

// Merge the static meshes under the selected actors, delete intermediate actors (AActors), keeps all the others actors
void UDigitalTwinToolsFunctionLibrary::MergeUnderSelectedActors()
{
	FScopedTransaction Transaction(LOCTEXT("MergeActors", "Merge Static Mesh Actors"));
    if (!GEditor) return;
	
    // Get Subsystems
    UStaticMeshEditorSubsystem* StaticMeshEditorSubsystem = GEditor->GetEditorSubsystem<UStaticMeshEditorSubsystem>();
    ULevelEditorSubsystem* LevelEditorSubsystem = GEditor->GetEditorSubsystem<ULevelEditorSubsystem>();
    UEditorActorSubsystem* EditorActorSubsystem = GEditor->GetEditorSubsystem<UEditorActorSubsystem>();

    if (!LevelEditorSubsystem || !EditorActorSubsystem) return;

    // Get current level
    ULevel* CurrentLevel = LevelEditorSubsystem->GetCurrentLevel();
    if (!CurrentLevel) return;

    // Get the merged folder path
    FString MergedFolderPath = GetMergedFolderPath(CurrentLevel);

    // Get selected actors
    TArray<AActor*> SelectedActors = EditorActorSubsystem->GetSelectedLevelActors();

    // Process each selected actor
    for (AActor* SelectedActor : SelectedActors)
    {
        TArray<AActor*> Descendants;
        SelectedActor->GetAttachedActors(Descendants, true, true);

        TArray<AStaticMeshActor*> StaticMeshActors;
        TArray<AActor*> OtherActors;

        // Sort actors into StaticMeshActors and OtherActors
        for (AActor* Descendant : Descendants)
        {
        	if (Descendant->IsA<AStaticMeshActor>())
            {
        		StaticMeshActors.Add(Cast<AStaticMeshActor>(Descendant));
            }
        	else if (Descendant->GetClass() == AActor::StaticClass())
        	{
        		Descendant->Destroy();
        	}
	        else
	        {
	        	OtherActors.Add(Descendant);
	        }
        }

        // Attach non-static mesh actors to the selected actor
        for (AActor* OtherActor : OtherActors)
        {
            OtherActor->AttachToActor(SelectedActor, FAttachmentTransformRules::KeepWorldTransform);
        }

        // If there are more than one static mesh actors, merge them
        AStaticMeshActor* MergedActor = nullptr;
        if (StaticMeshActors.Num() > 1)
        {
            MergedActor = MergeStaticMeshActorsForSelection(StaticMeshActors, MergedFolderPath, SelectedActor->GetActorLabel(), StaticMeshEditorSubsystem);
        }
        else
        {
            // Create a merged actor from the first static mesh actor
            MergedActor = StaticMeshActors.IsValidIndex(0) ? StaticMeshActors[0] : nullptr;
            if (MergedActor)
            {
                MergedActor->SetActorLabel(SelectedActor->GetActorLabel().Left(12));
            }
        }

        // Attach merged actor to parent and adds it to the not deletion set
        if (MergedActor)
        {
        	MergedActor->AttachToActor(SelectedActor, FAttachmentTransformRules::KeepWorldTransform);
        }
    }
}

void UDigitalTwinToolsFunctionLibrary::SimplifyUnderSelected()
{
	if (!GEditor) return;

	FScopedTransaction Transaction(LOCTEXT("SimplifyActors", "Simplify Actors Structure"));

	ULevelEditorSubsystem* LevelEditorSubsystem = GEditor->GetEditorSubsystem<ULevelEditorSubsystem>();
	UEditorActorSubsystem* EditorActorSubsystem = GEditor->GetEditorSubsystem<UEditorActorSubsystem>();
	if (!LevelEditorSubsystem || !EditorActorSubsystem) return;

	ULevel* CurrentLevel = LevelEditorSubsystem->GetCurrentLevel();
	if (!CurrentLevel) return;

	// Get selected actors
	TArray<AActor*> SelectedActors = EditorActorSubsystem->GetSelectedLevelActors();

	for (AActor* SelectedActor : SelectedActors)
	{
		TArray<AActor*> Descendants;
		SelectedActor->GetAttachedActors(Descendants, true, true);

		// Delete AActors
		for (AActor* Descendant : Descendants)
		{
			if (Descendant->GetClass() == AActor::StaticClass())
			{
				Descendant->Destroy();
			}
			else
			{
				Descendant->AttachToActor(SelectedActor, FAttachmentTransformRules::KeepWorldTransform);
			}
		}
	}
}

TMap<FString, UMaterialInterface*> UDigitalTwinToolsFunctionLibrary::LoadMaterials(FString& CSVData)
{
	TMap<FString, UMaterialInterface*> Materials;
	UEditorAssetSubsystem* EditorAssetSubsystem = GEditor->GetEditorSubsystem<UEditorAssetSubsystem>();

	FCsvParser CsvParser(CSVData);
	const FCsvParser::FRows& Rows = CsvParser.GetRows();

	for (const TArray<const TCHAR*>& Row : Rows)
	{
		if (Row.Num() > 0)
		{
			FString MaterialPath = Row[0];
			if (!Materials.Contains(MaterialPath))
			{
				const FString PackageName = GetPackageName(MaterialPath);
				UObject* LoadedAsset = EditorAssetSubsystem->LoadAsset(PackageName);
				UMaterialInterface* Material = Cast<UMaterialInterface>(LoadedAsset);
				if (Material)
				{
					Materials.Add(MaterialPath, Material);
				}
			}
		}
	}

	return Materials;
}

FString UDigitalTwinToolsFunctionLibrary::GetPackageName(const FString& AssetPath)
{
	int32 DotIndex;
	if (AssetPath.FindChar('.', DotIndex))
	{
		return AssetPath.Left(DotIndex);
	}
	return AssetPath;
}

bool UDigitalTwinToolsFunctionLibrary::ContainsKeywords(const FString& Name, const TArray<FString>& Keywords)
{
	FString NameLower = Name.ToLower();
	for (const FString& Keyword : Keywords)
	{
		if (NameLower.Contains(Keyword.ToLower()))
		{
			return true;
		}
	}
	return false;
}

void UDigitalTwinToolsFunctionLibrary::ChangeMaterial(AStaticMeshActor* StaticMeshActor, UMaterialInterface* Material)
{
	if (!StaticMeshActor || !Material) return;

	UStaticMeshComponent* StaticMeshComponent = StaticMeshActor->GetStaticMeshComponent();
	if (!StaticMeshComponent) return;

	UStaticMesh* StaticMesh = StaticMeshComponent->GetStaticMesh();
	if (!StaticMesh) return;

	// Apply material to all actor's slots
	for (int32 MaterialIndex = 0; MaterialIndex < StaticMeshComponent->GetNumMaterials(); ++MaterialIndex)
	{
		StaticMeshComponent->SetMaterial(MaterialIndex, Material);
	}

	StaticMesh->Modify();
	for (int32 MaterialIndex = 0; MaterialIndex < StaticMesh->GetStaticMaterials().Num(); ++MaterialIndex)
	{
		StaticMesh->SetMaterial(MaterialIndex, Material);
	}
	
	UEditorAssetSubsystem* EditorAssetSubsystem = GEditor->GetEditorSubsystem<UEditorAssetSubsystem>();
	if (EditorAssetSubsystem)
	{
		EditorAssetSubsystem->SaveAsset(StaticMesh->GetPathName());
	}
}

void PrintTMap(const TMap<FString, TArray<FString>>& MyMap)
{
	for (const auto& Pair : MyMap)
	{
		FString Key = Pair.Key;
		const TArray<FString>& Values = Pair.Value;

		// Log the key
		UE_LOG(LogTemp, Warning, TEXT("Key: %s"), *Key);

		// Log all values in the array
		for (const FString& Value : Values)
		{
			UE_LOG(LogTemp, Warning, TEXT("  - Value: %s"), *Value);
		}
	}
}

void UDigitalTwinToolsFunctionLibrary::RunMaterialReplacement()
{
	UEditorActorSubsystem* EditorActorSubsystem = GEditor->GetEditorSubsystem<UEditorActorSubsystem>();
	UEditorAssetSubsystem* EditorAssetSubsystem = GEditor->GetEditorSubsystem<UEditorAssetSubsystem>();

	if (!EditorActorSubsystem || !EditorAssetSubsystem)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get subsystems"));
		return;
	}
	
	// CSV file path
	const FString CSVPath = OpenFileDialog();
	FString CSVData;
	if (!FPaths::FileExists(CSVPath))
	{
		UE_LOG(LogTemp, Error, TEXT("File does not exist!"));
	}
	FFileHelper::LoadFileToString(CSVData, *CSVPath);

	// Load materials from CSV
	TMap<FString, UMaterialInterface*> Materials = LoadMaterials(CSVData);

	if (Materials.Num() == 0)
	{
		UE_LOG(LogTemp, Error, TEXT("No materials loaded from CSV"));
		return;
	}

	// Create dictionary mapping materials to keywords
	TMap<FString, TArray<FString>> MaterialToKeywords;
	FCsvParser CsvParser(CSVData);
	const FCsvParser::FRows& Rows = CsvParser.GetRows();

	for (const TArray<const TCHAR*>& Row : Rows)
	{
		if (Row.Num() >= 2)
		{
			FString MaterialPath = Row[0];
			TArray<FString> Keywords;
			for (size_t i = 1; i < Row.Num(); ++i)
			{
				Keywords.Add(Row[i]);
			}
			MaterialToKeywords.Add(MaterialPath, Keywords);
		}
	}

	// PrintTMap(MaterialToKeywords);

	// Get all static mesh actors
	TArray<AActor*> Actors = EditorActorSubsystem->GetAllLevelActors();
	TArray<AStaticMeshActor*> StaticMeshActors;
	
	for (AActor* Actor : Actors)
	{
		if (AStaticMeshActor* StaticMeshActor = Cast<AStaticMeshActor>(Actor))
		{
			StaticMeshActors.Add(StaticMeshActor);
		}
	}

	// Process actors with progress dialog
	FScopedSlowTask SlowTask(StaticMeshActors.Num(), FText::FromString(FString::Printf(TEXT("Checking and Changing colors based on %s"), *CSVPath)));
	SlowTask.MakeDialog();

	for (AStaticMeshActor* StaticMeshActor : StaticMeshActors)
	{
		if (SlowTask.ShouldCancel())
		{
			break;
		}

		FString ActorLabel = StaticMeshActor->GetActorLabel();
		for (const auto& Pair : MaterialToKeywords)
		{
			const FString& MaterialPath = Pair.Key;
			const TArray<FString>& Keywords = Pair.Value;
            
			if (ContainsKeywords(ActorLabel, Keywords))
			{
				UE_LOG(LogTemp, Log, TEXT("%s contains one of the following keywords: %s"), *ActorLabel, *FString::Join(Keywords, TEXT(", ")));
                
				if (UMaterialInterface** MaterialPtr = Materials.Find(MaterialPath))
				{
					ChangeMaterial(StaticMeshActor, *MaterialPtr);
				}
			}
		}

		SlowTask.EnterProgressFrame(1);
	}
}

bool UDigitalTwinToolsFunctionLibrary::ValidateMeshMaterial(const TArray<FStaticMaterial>& StaticMaterials)
{
	static const TArray<EBlendMode> ValidBlendModes = { BLEND_Opaque, BLEND_Masked };

	for (const FStaticMaterial& StaticMaterial : StaticMaterials)
	{
		UMaterialInterface* MaterialInterface = StaticMaterial.MaterialInterface;
		if (!MaterialInterface) continue;

		EBlendMode ActualBlendMode = MaterialInterface->GetBlendMode();
		if (!ValidBlendModes.Contains(ActualBlendMode))
		{
			return false;
		}
	}
	return true;
}

void UDigitalTwinToolsFunctionLibrary::EnableNaniteOnStaticMesh(UStaticMesh* StaticMesh)
{
	if (!StaticMesh) return;

	// Get the existing settings
	FMeshNaniteSettings NaniteSettings = StaticMesh->NaniteSettings;
    
	if (!NaniteSettings.bEnabled)
	{
		// Enable Nanite
		NaniteSettings.bEnabled = true;
		
		NaniteSettings.PositionPrecision = 0;  
		NaniteSettings.NormalPrecision = 0;
		NaniteSettings.TrimRelativeError = 0.0f;
		
		if (UStaticMeshEditorSubsystem* StaticMeshEditorSubsystem = GEditor->GetEditorSubsystem<UStaticMeshEditorSubsystem>())
		{
			StaticMeshEditorSubsystem->SetNaniteSettings(StaticMesh, NaniteSettings, true);
		}
        
		StaticMesh->Build(false);
		StaticMesh->MarkPackageDirty();
	}
}

void UDigitalTwinToolsFunctionLibrary::EnableNaniteOnFolderStaticMeshes()
{
	// Load necessary modules
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	
	FString FolderPath = OpenFolderDialog();
	FString VirtualPath;
	FPackageName::TryConvertFilenameToLongPackageName(FolderPath, VirtualPath);

	// Retrieve staticMesh asset
	FARFilter Filter;
	Filter.ClassPaths.Add(UStaticMesh::StaticClass()->GetClassPathName());
	Filter.bRecursivePaths = true;
	Filter.PackagePaths.Add(*VirtualPath);
	

	TArray<FAssetData> AssetData;
	AssetRegistryModule.Get().GetAssets(Filter, AssetData);

	if (AssetData.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No static meshes found in folder: %s"), *FolderPath);
		return;
	}

	UE_LOG(LogTemp, Display, TEXT("Found %d static meshes in folder %s"), AssetData.Num(), *FolderPath);

	// Setup progress dialog
	FScopedSlowTask SlowTask(AssetData.Num(), FText::FromString("Converting meshes to Nanite"));
	SlowTask.MakeDialog(true);

	const int32 BatchSize = 500;
	int32 ProcessedMeshes = 0;
	TArray<UPackage*> PackagesToSave;

	for (int32 i = 0; i < AssetData.Num(); i++)
	{
		SlowTask.EnterProgressFrame(1);

		UStaticMesh* StaticMesh = Cast<UStaticMesh>(AssetData[i].GetAsset());
		if (!StaticMesh)
		{
			continue;
		}

		// Skip if Nanite is already enabled
		if (StaticMesh->NaniteSettings.bEnabled)
		{
			continue;
		}

		// Validate material blend modes
		if (!ValidateMeshMaterial(StaticMesh->GetStaticMaterials()))
		{
			UE_LOG(LogTemp, Warning, TEXT("Skipping %s due to invalid material blend modes"), *StaticMesh->GetName());
			continue;
		}

		// Enable Nanite
		EnableNaniteOnStaticMesh(StaticMesh);
		ProcessedMeshes++;

		// Collect the package for saving
		UPackage* Package = StaticMesh->GetOutermost();
		if (Package)
		{
			PackagesToSave.AddUnique(Package);
		}

		// Save every BatchSize meshes
		if ((i + 1) % BatchSize == 0 || (i + 1) == AssetData.Num())
		{
			for (UPackage* Pack : PackagesToSave)
			{
				FString PackageName =Pack->GetName();
				Pack->MarkPackageDirty();
                
				// Save the package
				FString PackageFileName = FPackageName::LongPackageNameToFilename(
					PackageName,
					FPackageName::GetAssetPackageExtension());
                
				FSavePackageArgs SaveArgs;
				SaveArgs.TopLevelFlags = RF_Standalone;
				SaveArgs.SaveFlags = SAVE_NoError;
                
				bool bSaved = UPackage::SavePackage(Pack, nullptr, *PackageFileName, SaveArgs);
                
				if (!bSaved)
				{
					UE_LOG(LogTemp, Error, TEXT("Failed to save package: %s"), *PackageName);
				}
			}
		}
	}
}

void UDigitalTwinToolsFunctionLibrary::SelectOverlappingStaticMeshes()
{
	
}

void UDigitalTwinToolsFunctionLibrary::CreateLODS()
{
	// Load necessary modules
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	
	FString FolderPath = OpenFolderDialog();
	FString VirtualPath;
	FPackageName::TryConvertFilenameToLongPackageName(FolderPath, VirtualPath);

	// Retrieve staticMesh asset
	FARFilter Filter;
	Filter.ClassPaths.Add(UStaticMesh::StaticClass()->GetClassPathName());
	Filter.bRecursivePaths = true;
	Filter.PackagePaths.Add(*VirtualPath);
	

	TArray<FAssetData> AssetData;
	AssetRegistryModule.Get().GetAssets(Filter, AssetData);

	if (AssetData.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No static meshes found in folder: %s"), *FolderPath);
		return;
	}

	UE_LOG(LogTemp, Display, TEXT("Found %d static meshes in folder %s"), AssetData.Num(), *FolderPath);

	FScopedSlowTask SlowTask(AssetData.Num(), FText::FromString("Creating LODS for static meshes"));
	SlowTask.MakeDialog(true);

	// TODO check if the mesh has already LODS

	for (int32 i = 0; i < AssetData.Num(); i++)
	{
		SlowTask.EnterProgressFrame(1);
		UStaticMesh* StaticMesh = Cast<UStaticMesh>(AssetData[i].GetAsset());
		
		if (!StaticMesh) { continue; }
		if (StaticMesh->NaniteSettings.bEnabled) { continue; }

		// Skip meshes that already have LODs
		if (StaticMesh->GetNumSourceModels() > 1)
		{
			UE_LOG(LogTemp, Display, TEXT("Skipping %s (already has LODs)"), *StaticMesh->GetName());
			continue;
		}

		// Create 4 LODs: LOD0 (original) + LOD1 (25%) + LOD2 (12%) + LOD3 (6%)
		const int32 NumLODs = 4;
		StaticMesh->SetNumSourceModels(NumLODs);

		// LOD1 → 25% triangles
		{
			FStaticMeshSourceModel& SrcModel = StaticMesh->GetSourceModel(1);
			SrcModel.ReductionSettings.PercentTriangles = 0.25f;  
			SrcModel.ReductionSettings.BaseLODModel = 0;
			SrcModel.ScreenSize = 0.5f;
		}

		// LOD2 → 12% triangles
		{
			FStaticMeshSourceModel& SrcModel = StaticMesh->GetSourceModel(2);
			SrcModel.ReductionSettings.PercentTriangles = 0.12f;  
			SrcModel.ReductionSettings.BaseLODModel = 0;
			SrcModel.ScreenSize = 0.25f;
		}

		// LOD3 → 6% triangles
		{
			FStaticMeshSourceModel& SrcModel = StaticMesh->GetSourceModel(3);
			SrcModel.ReductionSettings.PercentTriangles = 0.06f;  
			SrcModel.ReductionSettings.BaseLODModel = 0;
			SrcModel.ScreenSize = 0.125f;
		}

		// Mark dirty and apply
		StaticMesh->Modify();
		StaticMesh->Build(false);
		StaticMesh->PostEditChange();
		StaticMesh->MarkPackageDirty();
	}
}	
	


UMaterialInterface* UDigitalTwinToolsFunctionLibrary::CreateMaterialCopy(UMaterialInterface* OriginalMaterial, const FString& StaticMeshAssetName)
{
	if (!OriginalMaterial) return nullptr;
	
	FString OriginalMaterialName = OriginalMaterial->GetName();
	FString NewMaterialName = FString::Printf(TEXT("%s_%s"), *StaticMeshAssetName, *OriginalMaterialName);
	
	FString OriginalPackagePath = OriginalMaterial->GetPathName();
	FString PackageDir = FPackageName::GetLongPackagePath(OriginalPackagePath);
	
	FString NewPackagePath = FString::Printf(TEXT("%s/%s"), *PackageDir, *NewMaterialName);
	
	UPackage* NewPackage = CreatePackage(*NewPackagePath);
	if (!NewPackage)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to create package for new material: %s"), *NewPackagePath);
		return nullptr;
	}
    
	// Duplicate the material
	UMaterialInterface* NewMaterial = DuplicateObject<UMaterialInterface>(OriginalMaterial, NewPackage, *NewMaterialName);
	if (!NewMaterial)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to duplicate material: %s"), *OriginalMaterialName);
		return nullptr;
	}
	
	NewPackage->SetDirtyFlag(true);
	FAssetRegistryModule::AssetCreated(NewMaterial);
	return NewMaterial;
}

void UDigitalTwinToolsFunctionLibrary::SeparateColors()
{
	UEditorActorSubsystem* EditorActorSubsystem = GEditor->GetEditorSubsystem<UEditorActorSubsystem>();
	if (!EditorActorSubsystem)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get Subsystem"));
		return;
	}
	
	TArray<AActor*> SelectedActors = EditorActorSubsystem->GetSelectedLevelActors();
	TSet<UStaticMesh*> UniqueStaticMeshes;

	for (AActor* Actor : SelectedActors)
	{
		if (!Actor->IsA<AStaticMeshActor>()) continue;
            
		AStaticMeshActor* StaticMeshActor = Cast<AStaticMeshActor>(Actor);
		UStaticMeshComponent* MeshComponent = StaticMeshActor->GetStaticMeshComponent();
		if (!MeshComponent) continue;
            
		UStaticMesh* StaticMesh = MeshComponent->GetStaticMesh();
		if (StaticMesh)
		{
			UniqueStaticMeshes.Add(StaticMesh);
		}
	}

	for (UStaticMesh* StaticMesh : UniqueStaticMeshes)
	{
		FString StaticMeshAssetName = StaticMesh->GetName();
		int32 NumMaterials = StaticMesh->GetStaticMaterials().Num();
		
		for (int32 MaterialIndex = 0; MaterialIndex < NumMaterials; MaterialIndex++)
		{
			UMaterialInterface* OriginalMaterial = StaticMesh->GetMaterial(MaterialIndex);
			if (!OriginalMaterial)
				continue;
			

			if (ContainsKeywords(OriginalMaterial->GetName(), TArray<FString>{StaticMeshAssetName}))
			{
				continue;
			}
			// Create a copy of the material
			UMaterialInterface* NewMaterial = CreateMaterialCopy(OriginalMaterial, StaticMeshAssetName);
			if (!NewMaterial)
				continue;
                
			// Assign the new material to the same slot
			StaticMesh->SetMaterial(MaterialIndex, NewMaterial);
		}
	}
}

void UDigitalTwinToolsFunctionLibrary::SelectedAssetsInBrowser(TArray<UStaticMesh*>& OutStaticMeshes, TArray<UWorld*>& OutLevels)
{
	// Get the Content Browser module
	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");

	// Get selected assets
	TArray<FAssetData> SelectedAssets;
	ContentBrowserModule.Get().GetSelectedAssets(SelectedAssets);

	// Iterate through selected assets and filter by type
	for (const FAssetData& AssetData : SelectedAssets)
	{
		// Check if it's a Static Mesh
		if (AssetData.AssetClassPath.GetAssetName() == UStaticMesh::StaticClass()->GetFName())
		{
			UStaticMesh* StaticMesh = Cast<UStaticMesh>(AssetData.GetAsset());
			if (StaticMesh)
			{
				OutStaticMeshes.Add(StaticMesh);
				UE_LOG(LogTemp, Log, TEXT("Selected Static Mesh: %s"), *StaticMesh->GetName());
			}
		}
		// Check if it's a Level (World)
		else if (AssetData.AssetClassPath.GetAssetName() == UWorld::StaticClass()->GetFName())
		{
			UWorld* Level = Cast<UWorld>(AssetData.GetAsset());
			if (Level)
			{
				OutLevels.Add(Level);
				UE_LOG(LogTemp, Log, TEXT("Selected Level: %s"), *Level->GetName());
			}
		}
	}
    
	UE_LOG(LogTemp, Log, TEXT("Total Static Meshes selected: %d"), OutStaticMeshes.Num());
	UE_LOG(LogTemp, Log, TEXT("Total Levels selected: %d"), OutLevels.Num());
	
}

TArray<AActor*> UDigitalTwinToolsFunctionLibrary::FilterTopLevelActors(const TArray<AActor*>& ActorsToFilter)
{
	TArray<AActor*> Result;
	for (AActor* Actor : ActorsToFilter)
	{
		bool bIsChildOfAnother = false;
		
		for (AActor* OtherActor : ActorsToFilter)
		{
			if (Actor == OtherActor) continue;

			if (Actor->IsAttachedTo(OtherActor)) bIsChildOfAnother = true;
		}
		if (!bIsChildOfAnother) Result.Add(Actor);
	}
	return Result;
}


void UDigitalTwinToolsFunctionLibrary::SubstituteActors()
{
	FScopedTransaction Transaction(LOCTEXT("Substitute Actors", "Substitute Actors with selected Assets"));
	UWorld* World = GEditor->GetEditorWorldContext().World();
	if (!World) return;
	
	UEditorActorSubsystem* EditorActorSubsystem = GEditor->GetEditorSubsystem<UEditorActorSubsystem>();
	if (!EditorActorSubsystem) return;

	// Get the selected SM and Levels
	TArray<UStaticMesh*> StaticMeshes;
	TArray<UWorld*> Levels;
	SelectedAssetsInBrowser(StaticMeshes, Levels);

	TArray<AActor*> AllActors = EditorActorSubsystem->GetAllLevelActors();
	TArray<AActor*> ActorsSameName;
	
	for (AActor* Actor : AllActors)
	{
		const FString ActorLabel = Actor->GetActorLabel();
		
		for (UStaticMesh* StaticMesh : StaticMeshes)
		{
			const TArray<FString> Keywords = {StaticMesh->GetName()};
			if (ContainsKeywords(ActorLabel, Keywords))
			{
				ActorsSameName.Add(Actor);
			}
		}
	}
	
	TArray<AActor*> TopLevelActorsSameName = FilterTopLevelActors(ActorsSameName);
	 
	for (AActor* Actor : TopLevelActorsSameName)
	{
		const FString ActorLabel = Actor->GetActorLabel();

		 // Substitute Actors with StaticMeshesActors
		for (UStaticMesh* StaticMesh : StaticMeshes)
		{
			const TArray<FString> Keywords = {StaticMesh->GetName()};
			
			if (ContainsKeywords(ActorLabel, Keywords))
			{
				// Delete Actors under Top Actor
				TArray<AActor*> Descendants;
				Actor->GetAttachedActors(Descendants, true, true);

				// Delete AActors
				for (AActor* Descendant : Descendants)
				{
					Descendant->Destroy();
				}
				
				FActorSpawnParameters SpawnParams;
				SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
				
				FTransform ParentTransform = Actor->GetActorTransform();

				// Spawn new actor with same coordinates as the one with the same name
				AActor* NewActor = World->SpawnActor(
					AStaticMeshActor::StaticClass(),
					&ParentTransform,
					SpawnParams);
				
				if (NewActor)
				{
					AStaticMeshActor* StaticMeshActorNewActor = Cast<AStaticMeshActor>(NewActor);
					UStaticMeshComponent* MeshComponentNewActor = StaticMeshActorNewActor->GetStaticMeshComponent();
					if (MeshComponentNewActor)
					{
						MeshComponentNewActor->SetStaticMesh(StaticMesh);
					}

					FString UniqueName = GetUniqueActorLabel(ActorLabel);
					NewActor->SetActorLabel(UniqueName);
					NewActor->AttachToActor(Actor, FAttachmentTransformRules::KeepWorldTransform);

				}
			}
		}

		// Substitute Actors with LevelInstances
		for (UWorld* Level : Levels)
		{
			break;
		}
	}
}

#undef LOCTEXT_NAMESPACE