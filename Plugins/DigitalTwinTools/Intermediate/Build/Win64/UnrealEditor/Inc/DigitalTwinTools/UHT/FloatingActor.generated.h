// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FloatingActor.h"

#ifdef DIGITALTWINTOOLS_FloatingActor_generated_h
#error "FloatingActor.generated.h already included, missing '#pragma once' in FloatingActor.h"
#endif
#define DIGITALTWINTOOLS_FloatingActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AFloatingActor ***********************************************************
struct Z_Construct_UClass_AFloatingActor_Statics;
DIGITALTWINTOOLS_API UClass* Z_Construct_UClass_AFloatingActor_NoRegister();

#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_FloatingActor_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFloatingActor(); \
	friend struct ::Z_Construct_UClass_AFloatingActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DIGITALTWINTOOLS_API UClass* ::Z_Construct_UClass_AFloatingActor_NoRegister(); \
public: \
	DECLARE_CLASS2(AFloatingActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DigitalTwinTools"), Z_Construct_UClass_AFloatingActor_NoRegister) \
	DECLARE_SERIALIZER(AFloatingActor)


#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_FloatingActor_h_12_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AFloatingActor(AFloatingActor&&) = delete; \
	AFloatingActor(const AFloatingActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFloatingActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFloatingActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFloatingActor) \
	NO_API virtual ~AFloatingActor();


#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_FloatingActor_h_9_PROLOG
#define FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_FloatingActor_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_FloatingActor_h_12_INCLASS_NO_PURE_DECLS \
	FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_FloatingActor_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AFloatingActor;

// ********** End Class AFloatingActor *************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_dev_FCC_ee_H_Plugins_DigitalTwinTools_Source_DigitalTwinTools_Public_FloatingActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
