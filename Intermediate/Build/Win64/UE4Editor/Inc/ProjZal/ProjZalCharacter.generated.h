// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJZAL_ProjZalCharacter_generated_h
#error "ProjZalCharacter.generated.h already included, missing '#pragma once' in ProjZalCharacter.h"
#endif
#define PROJZAL_ProjZalCharacter_generated_h

#define ProjZal_Source_ProjZal_ProjZalCharacter_h_13_RPC_WRAPPERS
#define ProjZal_Source_ProjZal_ProjZalCharacter_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define ProjZal_Source_ProjZal_ProjZalCharacter_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProjZalCharacter(); \
	friend PROJZAL_API class UClass* Z_Construct_UClass_AProjZalCharacter(); \
public: \
	DECLARE_CLASS(AProjZalCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ProjZal"), NO_API) \
	DECLARE_SERIALIZER(AProjZalCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ProjZal_Source_ProjZal_ProjZalCharacter_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAProjZalCharacter(); \
	friend PROJZAL_API class UClass* Z_Construct_UClass_AProjZalCharacter(); \
public: \
	DECLARE_CLASS(AProjZalCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ProjZal"), NO_API) \
	DECLARE_SERIALIZER(AProjZalCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ProjZal_Source_ProjZal_ProjZalCharacter_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AProjZalCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AProjZalCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjZalCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjZalCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProjZalCharacter(AProjZalCharacter&&); \
	NO_API AProjZalCharacter(const AProjZalCharacter&); \
public:


#define ProjZal_Source_ProjZal_ProjZalCharacter_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProjZalCharacter(AProjZalCharacter&&); \
	NO_API AProjZalCharacter(const AProjZalCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjZalCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjZalCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProjZalCharacter)


#define ProjZal_Source_ProjZal_ProjZalCharacter_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SpringArm() { return STRUCT_OFFSET(AProjZalCharacter, SpringArm); } \
	FORCEINLINE static uint32 __PPO__Camera() { return STRUCT_OFFSET(AProjZalCharacter, Camera); }


#define ProjZal_Source_ProjZal_ProjZalCharacter_h_10_PROLOG
#define ProjZal_Source_ProjZal_ProjZalCharacter_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjZal_Source_ProjZal_ProjZalCharacter_h_13_PRIVATE_PROPERTY_OFFSET \
	ProjZal_Source_ProjZal_ProjZalCharacter_h_13_RPC_WRAPPERS \
	ProjZal_Source_ProjZal_ProjZalCharacter_h_13_INCLASS \
	ProjZal_Source_ProjZal_ProjZalCharacter_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ProjZal_Source_ProjZal_ProjZalCharacter_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjZal_Source_ProjZal_ProjZalCharacter_h_13_PRIVATE_PROPERTY_OFFSET \
	ProjZal_Source_ProjZal_ProjZalCharacter_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	ProjZal_Source_ProjZal_ProjZalCharacter_h_13_INCLASS_NO_PURE_DECLS \
	ProjZal_Source_ProjZal_ProjZalCharacter_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ProjZal_Source_ProjZal_ProjZalCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
