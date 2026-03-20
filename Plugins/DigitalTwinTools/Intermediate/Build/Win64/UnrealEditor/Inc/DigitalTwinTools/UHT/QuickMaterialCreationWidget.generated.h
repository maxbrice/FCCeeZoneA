// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AssetActions/QuickMaterialCreationWidget.h"

#ifdef DIGITALTWINTOOLS_QuickMaterialCreationWidget_generated_h
#error "QuickMaterialCreationWidget.generated.h already included, missing '#pragma once' in QuickMaterialCreationWidget.h"
#endif
#define DIGITALTWINTOOLS_QuickMaterialCreationWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UQuickMaterialCreationWidget *********************************************
#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickMaterialCreationWidget_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execCreateMaterialFromSelectedTextures);


struct Z_Construct_UClass_UQuickMaterialCreationWidget_Statics;
DIGITALTWINTOOLS_API UClass* Z_Construct_UClass_UQuickMaterialCreationWidget_NoRegister();

#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickMaterialCreationWidget_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUQuickMaterialCreationWidget(); \
	friend struct ::Z_Construct_UClass_UQuickMaterialCreationWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DIGITALTWINTOOLS_API UClass* ::Z_Construct_UClass_UQuickMaterialCreationWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UQuickMaterialCreationWidget, UEditorUtilityWidget, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DigitalTwinTools"), Z_Construct_UClass_UQuickMaterialCreationWidget_NoRegister) \
	DECLARE_SERIALIZER(UQuickMaterialCreationWidget)


#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickMaterialCreationWidget_h_25_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuickMaterialCreationWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UQuickMaterialCreationWidget(UQuickMaterialCreationWidget&&) = delete; \
	UQuickMaterialCreationWidget(const UQuickMaterialCreationWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuickMaterialCreationWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuickMaterialCreationWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuickMaterialCreationWidget) \
	NO_API virtual ~UQuickMaterialCreationWidget();


#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickMaterialCreationWidget_h_22_PROLOG
#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickMaterialCreationWidget_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickMaterialCreationWidget_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickMaterialCreationWidget_h_25_INCLASS_NO_PURE_DECLS \
	FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickMaterialCreationWidget_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UQuickMaterialCreationWidget;

// ********** End Class UQuickMaterialCreationWidget ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_AssetActions_QuickMaterialCreationWidget_h

// ********** Begin Enum E_ChannelPackingType ******************************************************
#define FOREACH_ENUM_E_CHANNELPACKINGTYPE(op) \
	op(E_ChannelPackingType::ECPT_NoChannelPacking) \
	op(E_ChannelPackingType::ECPT_ORM) 

enum class E_ChannelPackingType : uint8;
template<> struct TIsUEnumClass<E_ChannelPackingType> { enum { Value = true }; };
template<> DIGITALTWINTOOLS_NON_ATTRIBUTED_API UEnum* StaticEnum<E_ChannelPackingType>();
// ********** End Enum E_ChannelPackingType ********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
