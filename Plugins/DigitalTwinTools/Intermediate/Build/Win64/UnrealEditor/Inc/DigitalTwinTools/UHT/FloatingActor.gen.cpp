// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FloatingActor.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeFloatingActor() {}

// ********** Begin Cross Module References ********************************************************
DIGITALTWINTOOLS_API UClass* Z_Construct_UClass_AFloatingActor();
DIGITALTWINTOOLS_API UClass* Z_Construct_UClass_AFloatingActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_DigitalTwinTools();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AFloatingActor ***********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AFloatingActor;
UClass* AFloatingActor::GetPrivateStaticClass()
{
	using TClass = AFloatingActor;
	if (!Z_Registration_Info_UClass_AFloatingActor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("FloatingActor"),
			Z_Registration_Info_UClass_AFloatingActor.InnerSingleton,
			StaticRegisterNativesAFloatingActor,
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
	return Z_Registration_Info_UClass_AFloatingActor.InnerSingleton;
}
UClass* Z_Construct_UClass_AFloatingActor_NoRegister()
{
	return AFloatingActor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AFloatingActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "FloatingActor.h" },
		{ "ModuleRelativePath", "Public/FloatingActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VisualMesh_MetaData[] = {
		{ "Category", "FloatingActor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * \n\x09 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/FloatingActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AFloatingActor constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VisualMesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AFloatingActor constinit property declarations *****************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFloatingActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AFloatingActor_Statics

// ********** Begin Class AFloatingActor Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFloatingActor_Statics::NewProp_VisualMesh = { "VisualMesh", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFloatingActor, VisualMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VisualMesh_MetaData), NewProp_VisualMesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFloatingActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFloatingActor_Statics::NewProp_VisualMesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingActor_Statics::PropPointers) < 2048);
// ********** End Class AFloatingActor Property Definitions ****************************************
UObject* (*const Z_Construct_UClass_AFloatingActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_DigitalTwinTools,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFloatingActor_Statics::ClassParams = {
	&AFloatingActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AFloatingActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingActor_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AFloatingActor_Statics::Class_MetaDataParams)
};
void AFloatingActor::StaticRegisterNativesAFloatingActor()
{
}
UClass* Z_Construct_UClass_AFloatingActor()
{
	if (!Z_Registration_Info_UClass_AFloatingActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFloatingActor.OuterSingleton, Z_Construct_UClass_AFloatingActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFloatingActor.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AFloatingActor);
AFloatingActor::~AFloatingActor() {}
// ********** End Class AFloatingActor *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_FloatingActor_h__Script_DigitalTwinTools_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFloatingActor, AFloatingActor::StaticClass, TEXT("AFloatingActor"), &Z_Registration_Info_UClass_AFloatingActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFloatingActor), 4125476581U) },
	};
}; // Z_CompiledInDeferFile_FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_FloatingActor_h__Script_DigitalTwinTools_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_FloatingActor_h__Script_DigitalTwinTools_60705619{
	TEXT("/Script/DigitalTwinTools"),
	Z_CompiledInDeferFile_FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_FloatingActor_h__Script_DigitalTwinTools_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_FloatingActor_h__Script_DigitalTwinTools_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
