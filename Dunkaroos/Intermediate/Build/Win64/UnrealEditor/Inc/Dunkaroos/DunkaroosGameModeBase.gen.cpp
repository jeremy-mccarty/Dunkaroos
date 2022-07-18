// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Dunkaroos/DunkaroosGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDunkaroosGameModeBase() {}
// Cross Module References
	DUNKAROOS_API UClass* Z_Construct_UClass_ADunkaroosGameModeBase_NoRegister();
	DUNKAROOS_API UClass* Z_Construct_UClass_ADunkaroosGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Dunkaroos();
// End Cross Module References
	void ADunkaroosGameModeBase::StaticRegisterNativesADunkaroosGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADunkaroosGameModeBase);
	UClass* Z_Construct_UClass_ADunkaroosGameModeBase_NoRegister()
	{
		return ADunkaroosGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ADunkaroosGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADunkaroosGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Dunkaroos,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADunkaroosGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "DunkaroosGameModeBase.h" },
		{ "ModuleRelativePath", "DunkaroosGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADunkaroosGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADunkaroosGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ADunkaroosGameModeBase_Statics::ClassParams = {
		&ADunkaroosGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ADunkaroosGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADunkaroosGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADunkaroosGameModeBase()
	{
		if (!Z_Registration_Info_UClass_ADunkaroosGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADunkaroosGameModeBase.OuterSingleton, Z_Construct_UClass_ADunkaroosGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ADunkaroosGameModeBase.OuterSingleton;
	}
	template<> DUNKAROOS_API UClass* StaticClass<ADunkaroosGameModeBase>()
	{
		return ADunkaroosGameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADunkaroosGameModeBase);
	struct Z_CompiledInDeferFile_FID_Dunkaroos_Source_Dunkaroos_DunkaroosGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Dunkaroos_Source_Dunkaroos_DunkaroosGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ADunkaroosGameModeBase, ADunkaroosGameModeBase::StaticClass, TEXT("ADunkaroosGameModeBase"), &Z_Registration_Info_UClass_ADunkaroosGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADunkaroosGameModeBase), 1661706823U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Dunkaroos_Source_Dunkaroos_DunkaroosGameModeBase_h_70182621(TEXT("/Script/Dunkaroos"),
		Z_CompiledInDeferFile_FID_Dunkaroos_Source_Dunkaroos_DunkaroosGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Dunkaroos_Source_Dunkaroos_DunkaroosGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
