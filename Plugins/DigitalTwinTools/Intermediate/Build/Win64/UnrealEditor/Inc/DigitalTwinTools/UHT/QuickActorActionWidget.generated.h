// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ActorAction/QuickActorActionWidget.h"

#ifdef DIGITALTWINTOOLS_QuickActorActionWidget_generated_h
#error "QuickActorActionWidget.generated.h already included, missing '#pragma once' in QuickActorActionWidget.h"
#endif
#define DIGITALTWINTOOLS_QuickActorActionWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FRandomActorRotation **********************************************
struct Z_Construct_UScriptStruct_FRandomActorRotation_Statics;
#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_ActorAction_QuickActorActionWidget_h_24_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FRandomActorRotation_Statics; \
	DIGITALTWINTOOLS_API static class UScriptStruct* StaticStruct();


struct FRandomActorRotation;
// ********** End ScriptStruct FRandomActorRotation ************************************************

// ********** Begin Class UQuickActorActionsWidget *************************************************
#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_ActorAction_QuickActorActionWidget_h_60_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRandomizeActorTransform); \
	DECLARE_FUNCTION(execDuplicateActors); \
	DECLARE_FUNCTION(execSelectAllActorsWithSimilarName); \
	DECLARE_FUNCTION(execImport3DXMLfiles);


struct Z_Construct_UClass_UQuickActorActionsWidget_Statics;
DIGITALTWINTOOLS_API UClass* Z_Construct_UClass_UQuickActorActionsWidget_NoRegister();

#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_ActorAction_QuickActorActionWidget_h_60_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUQuickActorActionsWidget(); \
	friend struct ::Z_Construct_UClass_UQuickActorActionsWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DIGITALTWINTOOLS_API UClass* ::Z_Construct_UClass_UQuickActorActionsWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UQuickActorActionsWidget, UEditorUtilityWidget, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DigitalTwinTools"), Z_Construct_UClass_UQuickActorActionsWidget_NoRegister) \
	DECLARE_SERIALIZER(UQuickActorActionsWidget)


#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_ActorAction_QuickActorActionWidget_h_60_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuickActorActionsWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UQuickActorActionsWidget(UQuickActorActionsWidget&&) = delete; \
	UQuickActorActionsWidget(const UQuickActorActionsWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuickActorActionsWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuickActorActionsWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuickActorActionsWidget) \
	NO_API virtual ~UQuickActorActionsWidget();


#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_ActorAction_QuickActorActionWidget_h_57_PROLOG
#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_ActorAction_QuickActorActionWidget_h_60_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_ActorAction_QuickActorActionWidget_h_60_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_ActorAction_QuickActorActionWidget_h_60_INCLASS_NO_PURE_DECLS \
	FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_ActorAction_QuickActorActionWidget_h_60_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UQuickActorActionsWidget;

// ********** End Class UQuickActorActionsWidget ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_ActorAction_QuickActorActionWidget_h

// ********** Begin Enum E_DuplicationAxis *********************************************************
#define FOREACH_ENUM_E_DUPLICATIONAXIS(op) \
	op(E_DuplicationAxis::EDA_XAxis) \
	op(E_DuplicationAxis::EDA_YAxis) \
	op(E_DuplicationAxis::EDA_ZAxis) 

enum class E_DuplicationAxis : uint8;
template<> struct TIsUEnumClass<E_DuplicationAxis> { enum { Value = true }; };
template<> DIGITALTWINTOOLS_NON_ATTRIBUTED_API UEnum* StaticEnum<E_DuplicationAxis>();
// ********** End Enum E_DuplicationAxis ***********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
