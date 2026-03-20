// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DigitalTwinToolsFunctionLibrary.h"

#ifdef DIGITALTWINTOOLS_DigitalTwinToolsFunctionLibrary_generated_h
#error "DigitalTwinToolsFunctionLibrary.generated.h already included, missing '#pragma once' in DigitalTwinToolsFunctionLibrary.h"
#endif
#define DIGITALTWINTOOLS_DigitalTwinToolsFunctionLibrary_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UDigitalTwinToolsFunctionLibrary *****************************************
#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_DigitalTwinToolsFunctionLibrary_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSelectOverlappingStaticMeshes); \
	DECLARE_FUNCTION(execEnableNaniteOnFolderStaticMeshes); \
	DECLARE_FUNCTION(execConsolidateEquivalentStaticMeshGroups); \
	DECLARE_FUNCTION(execLogEquivalentStaticMeshGroups); \
	DECLARE_FUNCTION(execRunMaterialReplacement); \
	DECLARE_FUNCTION(execSimplifyUnderSelected); \
	DECLARE_FUNCTION(execMergeUnderSelectedActors); \
	DECLARE_FUNCTION(execImportSceneFromFolder); \
	DECLARE_FUNCTION(execImportSceneFromFile);


struct Z_Construct_UClass_UDigitalTwinToolsFunctionLibrary_Statics;
DIGITALTWINTOOLS_API UClass* Z_Construct_UClass_UDigitalTwinToolsFunctionLibrary_NoRegister();

#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_DigitalTwinToolsFunctionLibrary_h_38_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDigitalTwinToolsFunctionLibrary(); \
	friend struct ::Z_Construct_UClass_UDigitalTwinToolsFunctionLibrary_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DIGITALTWINTOOLS_API UClass* ::Z_Construct_UClass_UDigitalTwinToolsFunctionLibrary_NoRegister(); \
public: \
	DECLARE_CLASS2(UDigitalTwinToolsFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DigitalTwinTools"), Z_Construct_UClass_UDigitalTwinToolsFunctionLibrary_NoRegister) \
	DECLARE_SERIALIZER(UDigitalTwinToolsFunctionLibrary)


#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_DigitalTwinToolsFunctionLibrary_h_38_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDigitalTwinToolsFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDigitalTwinToolsFunctionLibrary(UDigitalTwinToolsFunctionLibrary&&) = delete; \
	UDigitalTwinToolsFunctionLibrary(const UDigitalTwinToolsFunctionLibrary&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDigitalTwinToolsFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDigitalTwinToolsFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDigitalTwinToolsFunctionLibrary) \
	NO_API virtual ~UDigitalTwinToolsFunctionLibrary();


#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_DigitalTwinToolsFunctionLibrary_h_11_PROLOG
#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_DigitalTwinToolsFunctionLibrary_h_38_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_DigitalTwinToolsFunctionLibrary_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_DigitalTwinToolsFunctionLibrary_h_38_INCLASS_NO_PURE_DECLS \
	FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_DigitalTwinToolsFunctionLibrary_h_38_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDigitalTwinToolsFunctionLibrary;

// ********** End Class UDigitalTwinToolsFunctionLibrary *******************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_DigitalTwinToolsFunctionLibrary_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
