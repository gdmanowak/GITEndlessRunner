// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Floor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFloor() {}
// Cross Module References
	PROJZAL_API UClass* Z_Construct_UClass_AFloor_NoRegister();
	PROJZAL_API UClass* Z_Construct_UClass_AFloor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ProjZal();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AFloor::StaticRegisterNativesAFloor()
	{
	}
	UClass* Z_Construct_UClass_AFloor_NoRegister()
	{
		return AFloor::StaticClass();
	}
	UClass* Z_Construct_UClass_AFloor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_ProjZal,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "Floor.h" },
				{ "ModuleRelativePath", "Floor.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RockMesh_MetaData[] = {
				{ "Category", "Floor" },
				{ "ModuleRelativePath", "Floor.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RockMesh = { UE4CodeGen_Private::EPropertyClass::Object, "RockMesh", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AFloor, RockMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(NewProp_RockMesh_MetaData, ARRAY_COUNT(NewProp_RockMesh_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FloorMeshComponent_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Enemy" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Floor.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FloorMeshComponent = { UE4CodeGen_Private::EPropertyClass::Object, "FloorMeshComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x00400000000a001d, 1, nullptr, STRUCT_OFFSET(AFloor, FloorMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(NewProp_FloorMeshComponent_MetaData, ARRAY_COUNT(NewProp_FloorMeshComponent_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RockMesh,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_FloorMeshComponent,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AFloor>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AFloor::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFloor, 346933793);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFloor(Z_Construct_UClass_AFloor, &AFloor::StaticClass, TEXT("/Script/ProjZal"), TEXT("AFloor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFloor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
