// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ActorAction/QuickActorActionWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeQuickActorActionWidget() {}

// ********** Begin Cross Module References ********************************************************
BLUTILITY_API UClass* Z_Construct_UClass_UEditorUtilityWidget();
COREUOBJECT_API UEnum* Z_Construct_UEnum_CoreUObject_ESearchCase();
DIGITALTWINTOOLS_API UClass* Z_Construct_UClass_UQuickActorActionsWidget();
DIGITALTWINTOOLS_API UClass* Z_Construct_UClass_UQuickActorActionsWidget_NoRegister();
DIGITALTWINTOOLS_API UEnum* Z_Construct_UEnum_DigitalTwinTools_E_DuplicationAxis();
DIGITALTWINTOOLS_API UScriptStruct* Z_Construct_UScriptStruct_FRandomActorRotation();
UNREALED_API UClass* Z_Construct_UClass_UEditorActorSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_DigitalTwinTools();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum E_DuplicationAxis *********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_E_DuplicationAxis;
static UEnum* E_DuplicationAxis_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_E_DuplicationAxis.OuterSingleton)
	{
		Z_Registration_Info_UEnum_E_DuplicationAxis.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigitalTwinTools_E_DuplicationAxis, (UObject*)Z_Construct_UPackage__Script_DigitalTwinTools(), TEXT("E_DuplicationAxis"));
	}
	return Z_Registration_Info_UEnum_E_DuplicationAxis.OuterSingleton;
}
template<> DIGITALTWINTOOLS_NON_ATTRIBUTED_API UEnum* StaticEnum<E_DuplicationAxis>()
{
	return E_DuplicationAxis_StaticEnum();
}
struct Z_Construct_UEnum_DigitalTwinTools_E_DuplicationAxis_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "EDA_MAX.DisplayName", "Default Max" },
		{ "EDA_MAX.Name", "E_DuplicationAxis::EDA_MAX" },
		{ "EDA_XAxis.DisplayName", "X Axis" },
		{ "EDA_XAxis.Name", "E_DuplicationAxis::EDA_XAxis" },
		{ "EDA_YAxis.DisplayName", "Y Axis" },
		{ "EDA_YAxis.Name", "E_DuplicationAxis::EDA_YAxis" },
		{ "EDA_ZAxis.DisplayName", "Z Axis" },
		{ "EDA_ZAxis.Name", "E_DuplicationAxis::EDA_ZAxis" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "E_DuplicationAxis::EDA_XAxis", (int64)E_DuplicationAxis::EDA_XAxis },
		{ "E_DuplicationAxis::EDA_YAxis", (int64)E_DuplicationAxis::EDA_YAxis },
		{ "E_DuplicationAxis::EDA_ZAxis", (int64)E_DuplicationAxis::EDA_ZAxis },
		{ "E_DuplicationAxis::EDA_MAX", (int64)E_DuplicationAxis::EDA_MAX },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_DigitalTwinTools_E_DuplicationAxis_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_DigitalTwinTools_E_DuplicationAxis_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_DigitalTwinTools,
	nullptr,
	"E_DuplicationAxis",
	"E_DuplicationAxis",
	Z_Construct_UEnum_DigitalTwinTools_E_DuplicationAxis_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_DigitalTwinTools_E_DuplicationAxis_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_DigitalTwinTools_E_DuplicationAxis_Statics::Enum_MetaDataParams), Z_Construct_UEnum_DigitalTwinTools_E_DuplicationAxis_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_DigitalTwinTools_E_DuplicationAxis()
{
	if (!Z_Registration_Info_UEnum_E_DuplicationAxis.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_E_DuplicationAxis.InnerSingleton, Z_Construct_UEnum_DigitalTwinTools_E_DuplicationAxis_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_E_DuplicationAxis.InnerSingleton;
}
// ********** End Enum E_DuplicationAxis ***********************************************************

// ********** Begin ScriptStruct FRandomActorRotation **********************************************
struct Z_Construct_UScriptStruct_FRandomActorRotation_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FRandomActorRotation); }
	static inline consteval int16 GetStructAlignment() { return alignof(FRandomActorRotation); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRandomizeRotYaw_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotYawMin_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "EditCondition", "bRandomizeRotYaw" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotYawMax_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "EditCondition", "bRandomizeRotYaw" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRandomizeRotPitch_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotPitchMin_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "EditCondition", "bRandomizeRotPitch" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotPitchMax_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "EditCondition", "bRandomizeRotPitch" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRandomizeRotRoll_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotRollMin_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "EditCondition", "bRandomizeRotRoll" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotRollMax_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "EditCondition", "bRandomizeRotRoll" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FRandomActorRotation constinit property declarations **************
	static void NewProp_bRandomizeRotYaw_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomizeRotYaw;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotYawMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotYawMax;
	static void NewProp_bRandomizeRotPitch_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomizeRotPitch;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotPitchMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotPitchMax;
	static void NewProp_bRandomizeRotRoll_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomizeRotRoll;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotRollMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotRollMax;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FRandomActorRotation constinit property declarations ****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRandomActorRotation>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FRandomActorRotation_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FRandomActorRotation;
class UScriptStruct* FRandomActorRotation::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FRandomActorRotation.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FRandomActorRotation.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRandomActorRotation, (UObject*)Z_Construct_UPackage__Script_DigitalTwinTools(), TEXT("RandomActorRotation"));
	}
	return Z_Registration_Info_UScriptStruct_FRandomActorRotation.OuterSingleton;
	}

// ********** Begin ScriptStruct FRandomActorRotation Property Definitions *************************
void Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotYaw_SetBit(void* Obj)
{
	((FRandomActorRotation*)Obj)->bRandomizeRotYaw = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotYaw = { "bRandomizeRotYaw", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FRandomActorRotation), &Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotYaw_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRandomizeRotYaw_MetaData), NewProp_bRandomizeRotYaw_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotYawMin = { "RotYawMin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRandomActorRotation, RotYawMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotYawMin_MetaData), NewProp_RotYawMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotYawMax = { "RotYawMax", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRandomActorRotation, RotYawMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotYawMax_MetaData), NewProp_RotYawMax_MetaData) };
void Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotPitch_SetBit(void* Obj)
{
	((FRandomActorRotation*)Obj)->bRandomizeRotPitch = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotPitch = { "bRandomizeRotPitch", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FRandomActorRotation), &Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotPitch_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRandomizeRotPitch_MetaData), NewProp_bRandomizeRotPitch_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotPitchMin = { "RotPitchMin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRandomActorRotation, RotPitchMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotPitchMin_MetaData), NewProp_RotPitchMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotPitchMax = { "RotPitchMax", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRandomActorRotation, RotPitchMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotPitchMax_MetaData), NewProp_RotPitchMax_MetaData) };
void Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotRoll_SetBit(void* Obj)
{
	((FRandomActorRotation*)Obj)->bRandomizeRotRoll = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotRoll = { "bRandomizeRotRoll", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FRandomActorRotation), &Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotRoll_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRandomizeRotRoll_MetaData), NewProp_bRandomizeRotRoll_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotRollMin = { "RotRollMin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRandomActorRotation, RotRollMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotRollMin_MetaData), NewProp_RotRollMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotRollMax = { "RotRollMax", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRandomActorRotation, RotRollMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotRollMax_MetaData), NewProp_RotRollMax_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FRandomActorRotation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotYaw,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotYawMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotYawMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotPitch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotPitchMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotPitchMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotRoll,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotRollMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotRollMax,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FRandomActorRotation Property Definitions ***************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DigitalTwinTools,
	nullptr,
	&NewStructOps,
	"RandomActorRotation",
	Z_Construct_UScriptStruct_FRandomActorRotation_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::PropPointers),
	sizeof(FRandomActorRotation),
	alignof(FRandomActorRotation),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FRandomActorRotation_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FRandomActorRotation()
{
	if (!Z_Registration_Info_UScriptStruct_FRandomActorRotation.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FRandomActorRotation.InnerSingleton, Z_Construct_UScriptStruct_FRandomActorRotation_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FRandomActorRotation.InnerSingleton);
}
// ********** End ScriptStruct FRandomActorRotation ************************************************

// ********** Begin Class UQuickActorActionsWidget Function DuplicateActors ************************
struct Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ActorBatchDuplication" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function DuplicateActors constinit property declarations ***********************
// ********** End Function DuplicateActors constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UQuickActorActionsWidget, nullptr, "DuplicateActors", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuickActorActionsWidget::execDuplicateActors)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DuplicateActors();
	P_NATIVE_END;
}
// ********** End Class UQuickActorActionsWidget Function DuplicateActors **************************

// ********** Begin Class UQuickActorActionsWidget Function Import3DXMLfiles ***********************
struct Z_Construct_UFunction_UQuickActorActionsWidget_Import3DXMLfiles_Statics
{
	struct QuickActorActionsWidget_eventImport3DXMLfiles_Parms
	{
		FString FilePath;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "3DXMLImport" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Import3DXMLfiles constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FilePath;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Import3DXMLfiles constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Import3DXMLfiles Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UQuickActorActionsWidget_Import3DXMLfiles_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(QuickActorActionsWidget_eventImport3DXMLfiles_Parms, FilePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilePath_MetaData), NewProp_FilePath_MetaData) };
void Z_Construct_UFunction_UQuickActorActionsWidget_Import3DXMLfiles_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((QuickActorActionsWidget_eventImport3DXMLfiles_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UQuickActorActionsWidget_Import3DXMLfiles_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(QuickActorActionsWidget_eventImport3DXMLfiles_Parms), &Z_Construct_UFunction_UQuickActorActionsWidget_Import3DXMLfiles_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UQuickActorActionsWidget_Import3DXMLfiles_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuickActorActionsWidget_Import3DXMLfiles_Statics::NewProp_FilePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuickActorActionsWidget_Import3DXMLfiles_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickActorActionsWidget_Import3DXMLfiles_Statics::PropPointers) < 2048);
// ********** End Function Import3DXMLfiles Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickActorActionsWidget_Import3DXMLfiles_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UQuickActorActionsWidget, nullptr, "Import3DXMLfiles", 	Z_Construct_UFunction_UQuickActorActionsWidget_Import3DXMLfiles_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickActorActionsWidget_Import3DXMLfiles_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UQuickActorActionsWidget_Import3DXMLfiles_Statics::QuickActorActionsWidget_eventImport3DXMLfiles_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickActorActionsWidget_Import3DXMLfiles_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuickActorActionsWidget_Import3DXMLfiles_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UQuickActorActionsWidget_Import3DXMLfiles_Statics::QuickActorActionsWidget_eventImport3DXMLfiles_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UQuickActorActionsWidget_Import3DXMLfiles()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickActorActionsWidget_Import3DXMLfiles_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuickActorActionsWidget::execImport3DXMLfiles)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FilePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Import3DXMLfiles(Z_Param_FilePath);
	P_NATIVE_END;
}
// ********** End Class UQuickActorActionsWidget Function Import3DXMLfiles *************************

// ********** Begin Class UQuickActorActionsWidget Function RandomizeActorTransform ****************
struct Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RandomizeActorTransform constinit property declarations ***************
// ********** End Function RandomizeActorTransform constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UQuickActorActionsWidget, nullptr, "RandomizeActorTransform", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuickActorActionsWidget::execRandomizeActorTransform)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RandomizeActorTransform();
	P_NATIVE_END;
}
// ********** End Class UQuickActorActionsWidget Function RandomizeActorTransform ******************

// ********** Begin Class UQuickActorActionsWidget Function SelectAllActorsWithSimilarName *********
struct Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ActorBatchSelection" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SelectAllActorsWithSimilarName constinit property declarations ********
// ********** End Function SelectAllActorsWithSimilarName constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UQuickActorActionsWidget, nullptr, "SelectAllActorsWithSimilarName", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuickActorActionsWidget::execSelectAllActorsWithSimilarName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SelectAllActorsWithSimilarName();
	P_NATIVE_END;
}
// ********** End Class UQuickActorActionsWidget Function SelectAllActorsWithSimilarName ***********

// ********** Begin Class UQuickActorActionsWidget *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UQuickActorActionsWidget;
UClass* UQuickActorActionsWidget::GetPrivateStaticClass()
{
	using TClass = UQuickActorActionsWidget;
	if (!Z_Registration_Info_UClass_UQuickActorActionsWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("QuickActorActionsWidget"),
			Z_Registration_Info_UClass_UQuickActorActionsWidget.InnerSingleton,
			StaticRegisterNativesUQuickActorActionsWidget,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UQuickActorActionsWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UQuickActorActionsWidget_NoRegister()
{
	return UQuickActorActionsWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UQuickActorActionsWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "ActorAction/QuickActorActionWidget.h" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SearchCase_MetaData[] = {
		{ "Category", "ActorBatchSelection" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AxisForDuplication_MetaData[] = {
		{ "Category", "ActorBatchDuplication" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NumberOfDuplicates_MetaData[] = {
		{ "Category", "ActorBatchDuplication" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OffsetDist_MetaData[] = {
		{ "Category", "ActorBatchDuplication" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RandomActorRotation_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRandomizeScale_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScaleMin_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "EditCondition", "bRandomizeScale" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScaleMax_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "EditCondition", "bRandomizeScale" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRandomizeOffset_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OffsetMin_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "EditCondition", "bRandomizeOffset" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OffsetMax_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "EditCondition", "bRandomizeOffset" },
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EditorActorSubsystem_MetaData[] = {
		{ "ModuleRelativePath", "Public/ActorAction/QuickActorActionWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UQuickActorActionsWidget constinit property declarations *****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_SearchCase;
	static const UECodeGen_Private::FBytePropertyParams NewProp_AxisForDuplication_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_AxisForDuplication;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumberOfDuplicates;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OffsetDist;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RandomActorRotation;
	static void NewProp_bRandomizeScale_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomizeScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScaleMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScaleMax;
	static void NewProp_bRandomizeOffset_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomizeOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OffsetMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OffsetMax;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EditorActorSubsystem;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UQuickActorActionsWidget constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("DuplicateActors"), .Pointer = &UQuickActorActionsWidget::execDuplicateActors },
		{ .NameUTF8 = UTF8TEXT("Import3DXMLfiles"), .Pointer = &UQuickActorActionsWidget::execImport3DXMLfiles },
		{ .NameUTF8 = UTF8TEXT("RandomizeActorTransform"), .Pointer = &UQuickActorActionsWidget::execRandomizeActorTransform },
		{ .NameUTF8 = UTF8TEXT("SelectAllActorsWithSimilarName"), .Pointer = &UQuickActorActionsWidget::execSelectAllActorsWithSimilarName },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors, "DuplicateActors" }, // 3960128550
		{ &Z_Construct_UFunction_UQuickActorActionsWidget_Import3DXMLfiles, "Import3DXMLfiles" }, // 1242397797
		{ &Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform, "RandomizeActorTransform" }, // 3563438643
		{ &Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName, "SelectAllActorsWithSimilarName" }, // 1987625779
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuickActorActionsWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UQuickActorActionsWidget_Statics

// ********** Begin Class UQuickActorActionsWidget Property Definitions ****************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_SearchCase = { "SearchCase", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, SearchCase), Z_Construct_UEnum_CoreUObject_ESearchCase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SearchCase_MetaData), NewProp_SearchCase_MetaData) }; // 1099345106
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_AxisForDuplication_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_AxisForDuplication = { "AxisForDuplication", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, AxisForDuplication), Z_Construct_UEnum_DigitalTwinTools_E_DuplicationAxis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AxisForDuplication_MetaData), NewProp_AxisForDuplication_MetaData) }; // 721253681
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_NumberOfDuplicates = { "NumberOfDuplicates", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, NumberOfDuplicates), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NumberOfDuplicates_MetaData), NewProp_NumberOfDuplicates_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetDist = { "OffsetDist", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, OffsetDist), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OffsetDist_MetaData), NewProp_OffsetDist_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_RandomActorRotation = { "RandomActorRotation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, RandomActorRotation), Z_Construct_UScriptStruct_FRandomActorRotation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RandomActorRotation_MetaData), NewProp_RandomActorRotation_MetaData) }; // 4129827241
void Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeScale_SetBit(void* Obj)
{
	((UQuickActorActionsWidget*)Obj)->bRandomizeScale = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeScale = { "bRandomizeScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UQuickActorActionsWidget), &Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeScale_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRandomizeScale_MetaData), NewProp_bRandomizeScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_ScaleMin = { "ScaleMin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, ScaleMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScaleMin_MetaData), NewProp_ScaleMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_ScaleMax = { "ScaleMax", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, ScaleMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScaleMax_MetaData), NewProp_ScaleMax_MetaData) };
void Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeOffset_SetBit(void* Obj)
{
	((UQuickActorActionsWidget*)Obj)->bRandomizeOffset = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeOffset = { "bRandomizeOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UQuickActorActionsWidget), &Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeOffset_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRandomizeOffset_MetaData), NewProp_bRandomizeOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetMin = { "OffsetMin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, OffsetMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OffsetMin_MetaData), NewProp_OffsetMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetMax = { "OffsetMax", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, OffsetMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OffsetMax_MetaData), NewProp_OffsetMax_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_EditorActorSubsystem = { "EditorActorSubsystem", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, EditorActorSubsystem), Z_Construct_UClass_UEditorActorSubsystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EditorActorSubsystem_MetaData), NewProp_EditorActorSubsystem_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuickActorActionsWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_SearchCase,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_AxisForDuplication_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_AxisForDuplication,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_NumberOfDuplicates,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetDist,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_RandomActorRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_ScaleMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_ScaleMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_EditorActorSubsystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::PropPointers) < 2048);
// ********** End Class UQuickActorActionsWidget Property Definitions ******************************
UObject* (*const Z_Construct_UClass_UQuickActorActionsWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEditorUtilityWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_DigitalTwinTools,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::ClassParams = {
	&UQuickActorActionsWidget::StaticClass,
	"Editor",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UQuickActorActionsWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::PropPointers),
	0,
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UQuickActorActionsWidget_Statics::Class_MetaDataParams)
};
void UQuickActorActionsWidget::StaticRegisterNativesUQuickActorActionsWidget()
{
	UClass* Class = UQuickActorActionsWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UQuickActorActionsWidget_Statics::Funcs));
}
UClass* Z_Construct_UClass_UQuickActorActionsWidget()
{
	if (!Z_Registration_Info_UClass_UQuickActorActionsWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UQuickActorActionsWidget.OuterSingleton, Z_Construct_UClass_UQuickActorActionsWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UQuickActorActionsWidget.OuterSingleton;
}
UQuickActorActionsWidget::UQuickActorActionsWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UQuickActorActionsWidget);
UQuickActorActionsWidget::~UQuickActorActionsWidget() {}
// ********** End Class UQuickActorActionsWidget ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_ActorAction_QuickActorActionWidget_h__Script_DigitalTwinTools_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ E_DuplicationAxis_StaticEnum, TEXT("E_DuplicationAxis"), &Z_Registration_Info_UEnum_E_DuplicationAxis, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 721253681U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FRandomActorRotation::StaticStruct, Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewStructOps, TEXT("RandomActorRotation"),&Z_Registration_Info_UScriptStruct_FRandomActorRotation, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRandomActorRotation), 4129827241U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UQuickActorActionsWidget, UQuickActorActionsWidget::StaticClass, TEXT("UQuickActorActionsWidget"), &Z_Registration_Info_UClass_UQuickActorActionsWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UQuickActorActionsWidget), 3137561000U) },
	};
}; // Z_CompiledInDeferFile_FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_ActorAction_QuickActorActionWidget_h__Script_DigitalTwinTools_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_ActorAction_QuickActorActionWidget_h__Script_DigitalTwinTools_3857357835{
	TEXT("/Script/DigitalTwinTools"),
	Z_CompiledInDeferFile_FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_ActorAction_QuickActorActionWidget_h__Script_DigitalTwinTools_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_ActorAction_QuickActorActionWidget_h__Script_DigitalTwinTools_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_ActorAction_QuickActorActionWidget_h__Script_DigitalTwinTools_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_ActorAction_QuickActorActionWidget_h__Script_DigitalTwinTools_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_ActorAction_QuickActorActionWidget_h__Script_DigitalTwinTools_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_ActorAction_QuickActorActionWidget_h__Script_DigitalTwinTools_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
