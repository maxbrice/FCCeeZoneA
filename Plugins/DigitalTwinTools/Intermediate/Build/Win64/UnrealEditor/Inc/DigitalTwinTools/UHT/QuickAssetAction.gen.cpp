// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AssetActions/QuickAssetAction.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeQuickAssetAction() {}

// ********** Begin Cross Module References ********************************************************
BLUTILITY_API UClass* Z_Construct_UClass_UAssetActionUtility();
DIGITALTWINTOOLS_API UClass* Z_Construct_UClass_UQuickAssetAction();
DIGITALTWINTOOLS_API UClass* Z_Construct_UClass_UQuickAssetAction_NoRegister();
UPackage* Z_Construct_UPackage__Script_DigitalTwinTools();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UQuickAssetAction Function AddPrefixes ***********************************
struct Z_Construct_UFunction_UQuickAssetAction_AddPrefixes_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/AssetActions/QuickAssetAction.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddPrefixes constinit property declarations ***************************
// ********** End Function AddPrefixes constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickAssetAction_AddPrefixes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UQuickAssetAction, nullptr, "AddPrefixes", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickAssetAction_AddPrefixes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuickAssetAction_AddPrefixes_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UQuickAssetAction_AddPrefixes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickAssetAction_AddPrefixes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuickAssetAction::execAddPrefixes)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddPrefixes();
	P_NATIVE_END;
}
// ********** End Class UQuickAssetAction Function AddPrefixes *************************************

// ********** Begin Class UQuickAssetAction Function DuplicateAssets *******************************
struct Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics
{
	struct QuickAssetAction_eventDuplicateAssets_Parms
	{
		int32 NumOfDuplicates;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/AssetActions/QuickAssetAction.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function DuplicateAssets constinit property declarations ***********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumOfDuplicates;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DuplicateAssets constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DuplicateAssets Property Definitions **********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::NewProp_NumOfDuplicates = { "NumOfDuplicates", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(QuickAssetAction_eventDuplicateAssets_Parms, NumOfDuplicates), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::NewProp_NumOfDuplicates,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::PropPointers) < 2048);
// ********** End Function DuplicateAssets Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UQuickAssetAction, nullptr, "DuplicateAssets", 	Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::QuickAssetAction_eventDuplicateAssets_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::QuickAssetAction_eventDuplicateAssets_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuickAssetAction::execDuplicateAssets)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_NumOfDuplicates);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DuplicateAssets(Z_Param_NumOfDuplicates);
	P_NATIVE_END;
}
// ********** End Class UQuickAssetAction Function DuplicateAssets *********************************

// ********** Begin Class UQuickAssetAction Function RemoveUnusedAssets ****************************
struct Z_Construct_UFunction_UQuickAssetAction_RemoveUnusedAssets_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/AssetActions/QuickAssetAction.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveUnusedAssets constinit property declarations ********************
// ********** End Function RemoveUnusedAssets constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickAssetAction_RemoveUnusedAssets_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UQuickAssetAction, nullptr, "RemoveUnusedAssets", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickAssetAction_RemoveUnusedAssets_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuickAssetAction_RemoveUnusedAssets_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UQuickAssetAction_RemoveUnusedAssets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickAssetAction_RemoveUnusedAssets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuickAssetAction::execRemoveUnusedAssets)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RemoveUnusedAssets();
	P_NATIVE_END;
}
// ********** End Class UQuickAssetAction Function RemoveUnusedAssets ******************************

// ********** Begin Class UQuickAssetAction ********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UQuickAssetAction;
UClass* UQuickAssetAction::GetPrivateStaticClass()
{
	using TClass = UQuickAssetAction;
	if (!Z_Registration_Info_UClass_UQuickAssetAction.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("QuickAssetAction"),
			Z_Registration_Info_UClass_UQuickAssetAction.InnerSingleton,
			StaticRegisterNativesUQuickAssetAction,
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
	return Z_Registration_Info_UClass_UQuickAssetAction.InnerSingleton;
}
UClass* Z_Construct_UClass_UQuickAssetAction_NoRegister()
{
	return UQuickAssetAction::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UQuickAssetAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Object" },
		{ "IncludePath", "AssetActions/QuickAssetAction.h" },
		{ "ModuleRelativePath", "Public/AssetActions/QuickAssetAction.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UQuickAssetAction constinit property declarations ************************
// ********** End Class UQuickAssetAction constinit property declarations **************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddPrefixes"), .Pointer = &UQuickAssetAction::execAddPrefixes },
		{ .NameUTF8 = UTF8TEXT("DuplicateAssets"), .Pointer = &UQuickAssetAction::execDuplicateAssets },
		{ .NameUTF8 = UTF8TEXT("RemoveUnusedAssets"), .Pointer = &UQuickAssetAction::execRemoveUnusedAssets },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuickAssetAction_AddPrefixes, "AddPrefixes" }, // 3649794521
		{ &Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets, "DuplicateAssets" }, // 3885894917
		{ &Z_Construct_UFunction_UQuickAssetAction_RemoveUnusedAssets, "RemoveUnusedAssets" }, // 1670858343
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuickAssetAction>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UQuickAssetAction_Statics
UObject* (*const Z_Construct_UClass_UQuickAssetAction_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAssetActionUtility,
	(UObject* (*)())Z_Construct_UPackage__Script_DigitalTwinTools,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuickAssetAction_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UQuickAssetAction_Statics::ClassParams = {
	&UQuickAssetAction::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuickAssetAction_Statics::Class_MetaDataParams), Z_Construct_UClass_UQuickAssetAction_Statics::Class_MetaDataParams)
};
void UQuickAssetAction::StaticRegisterNativesUQuickAssetAction()
{
	UClass* Class = UQuickAssetAction::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UQuickAssetAction_Statics::Funcs));
}
UClass* Z_Construct_UClass_UQuickAssetAction()
{
	if (!Z_Registration_Info_UClass_UQuickAssetAction.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UQuickAssetAction.OuterSingleton, Z_Construct_UClass_UQuickAssetAction_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UQuickAssetAction.OuterSingleton;
}
UQuickAssetAction::UQuickAssetAction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UQuickAssetAction);
UQuickAssetAction::~UQuickAssetAction() {}
// ********** End Class UQuickAssetAction **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickAssetAction_h__Script_DigitalTwinTools_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UQuickAssetAction, UQuickAssetAction::StaticClass, TEXT("UQuickAssetAction"), &Z_Registration_Info_UClass_UQuickAssetAction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UQuickAssetAction), 1964291101U) },
	};
}; // Z_CompiledInDeferFile_FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickAssetAction_h__Script_DigitalTwinTools_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickAssetAction_h__Script_DigitalTwinTools_2705195915{
	TEXT("/Script/DigitalTwinTools"),
	Z_CompiledInDeferFile_FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickAssetAction_h__Script_DigitalTwinTools_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickAssetAction_h__Script_DigitalTwinTools_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
