// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AssetActions/QuickAssetAction.h"

#ifdef DIGITALTWINTOOLS_QuickAssetAction_generated_h
#error "QuickAssetAction.generated.h already included, missing '#pragma once' in QuickAssetAction.h"
#endif
#define DIGITALTWINTOOLS_QuickAssetAction_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UQuickAssetAction ********************************************************
#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickAssetAction_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRemoveUnusedAssets); \
	DECLARE_FUNCTION(execDuplicateAssets); \
	DECLARE_FUNCTION(execAddPrefixes);


struct Z_Construct_UClass_UQuickAssetAction_Statics;
DIGITALTWINTOOLS_API UClass* Z_Construct_UClass_UQuickAssetAction_NoRegister();

#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickAssetAction_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUQuickAssetAction(); \
	friend struct ::Z_Construct_UClass_UQuickAssetAction_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DIGITALTWINTOOLS_API UClass* ::Z_Construct_UClass_UQuickAssetAction_NoRegister(); \
public: \
	DECLARE_CLASS2(UQuickAssetAction, UAssetActionUtility, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DigitalTwinTools"), Z_Construct_UClass_UQuickAssetAction_NoRegister) \
	DECLARE_SERIALIZER(UQuickAssetAction)


#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickAssetAction_h_25_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuickAssetAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UQuickAssetAction(UQuickAssetAction&&) = delete; \
	UQuickAssetAction(const UQuickAssetAction&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuickAssetAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuickAssetAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuickAssetAction) \
	NO_API virtual ~UQuickAssetAction();


#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickAssetAction_h_22_PROLOG
#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickAssetAction_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickAssetAction_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickAssetAction_h_25_INCLASS_NO_PURE_DECLS \
	FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickAssetAction_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UQuickAssetAction;

// ********** End Class UQuickAssetAction **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickAssetAction_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
