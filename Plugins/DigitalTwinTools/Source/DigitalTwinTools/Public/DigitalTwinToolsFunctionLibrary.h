#pragma once

#include "CoreMinimal.h"
#include "StaticMeshEditorSubsystem.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DigitalTwinToolsFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class DIGITALTWINTOOLS_API UDigitalTwinToolsFunctionLibrary : public UBlueprintFunctionLibrary
{
private:
	static UMaterialInterface* CreateMaterialCopy(UMaterialInterface* OriginalMaterial, const FString& StaticMeshAssetName);

	static void SelectedAssetsInBrowser(TArray<UStaticMesh*>& OutStaticMeshes, TArray<UWorld*>& OutLevels);
	static void ChangeMaterial(AStaticMeshActor* StaticMeshActor, UMaterialInterface* Material);
	static void RunPythonImport(const FString& FunctionName, const FString& Path);
	static void GetLevelStaticMeshes(TArray<UStaticMesh*>& OutStaticMeshes);
	static void EnableNaniteOnStaticMesh(UStaticMesh* StaticMesh);
	
	static bool ContainsKeywords(const FString& Name, const TArray<FString>& Keywords);
	static bool ValidateMeshMaterial(const TArray<FStaticMaterial>& StaticMaterials);
	static bool AreStaticMeshesEquivalent(UStaticMesh* MeshA, UStaticMesh* MeshB);
	
	static FString GetUniqueActorLabel(const FString& BaseName);
	static FString GetMergedFolderPath (ULevel* CurrentLevel);
	static FString GetPackageName(const FString& AssetPath);
	static FString OpenFolderDialog(const FString& DefaultPath = TEXT(""));
	static FString OpenFileDialog();
	
	static AStaticMeshActor* MergeStaticMeshActorsForSelection(
		const TArray<AStaticMeshActor*>& StaticMeshActors,
		const FString& MergedFolderPath,
		const FString& ActorLabel,
		UStaticMeshEditorSubsystem* StaticMeshEditorSubsystem);

	static TArray<TArray<UStaticMesh*>> GroupLevelEquivalentMeshes();

	static TArray<AActor*> FilterTopLevelActors(const TArray<AActor*>& InActors);
	
	static TMap<FString, UMaterialInterface*> LoadMaterials(FString& CSVPath);

	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Digital Twin Tools")
	static void ImportSceneFromFile();

	UFUNCTION(BlueprintCallable, Category = "Digital Twin Tools")
	static void ImportSceneFromFolder();
	
	UFUNCTION(BlueprintCallable, Category = "Digital Twin Tools")
	static void MergeUnderSelectedActors();

	UFUNCTION(BlueprintCallable, Category = "Digital Twin Tools")
	static void SimplifyUnderSelected();

	UFUNCTION(BlueprintCallable, Category = "Digital Twin Tools")
	static void RunMaterialReplacement();

	UFUNCTION(BlueprintCallable, Category = "Digital Twin Tools")
	static void LogEquivalentStaticMeshGroups();

	UFUNCTION(BlueprintCallable, Category = "Digital Twin Tools")
	static void ConsolidateEquivalentStaticMeshGroups();
	
	UFUNCTION(BLUEprintable, BlueprintCallable, Category = "Digital Twin Tools")
	static void EnableNaniteOnFolderStaticMeshes();
	
	UFUNCTION(BLUEprintable, BlueprintCallable, Category = "Digital Twin Tools")
	static void SelectOverlappingStaticMeshes();

	UFUNCTION(BLUEprintable, BlueprintCallable, Category = "Digital Twin Tools")
	static void CreateLODS();
	
	UFUNCTION(BLUEprintable, BlueprintCallable, Category = "Digital Twin Tools")
	static void SeparateColors();

	UFUNCTION(BLUEprintable, BlueprintCallable, Category = "Digital Twin Tools")
	static void SubstituteActors();
};