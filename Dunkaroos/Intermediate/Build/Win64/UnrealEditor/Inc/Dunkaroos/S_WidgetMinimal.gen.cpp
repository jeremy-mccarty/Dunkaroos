// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Dunkaroos/UI/S_WidgetMinimal.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeS_WidgetMinimal() {}
// Cross Module References
	DUNKAROOS_API UClass* Z_Construct_UClass_US_WidgetMinimal_NoRegister();
	DUNKAROOS_API UClass* Z_Construct_UClass_US_WidgetMinimal();
	UMG_API UClass* Z_Construct_UClass_UWidget();
	UPackage* Z_Construct_UPackage__Script_Dunkaroos();
// End Cross Module References
	void US_WidgetMinimal::StaticRegisterNativesUS_WidgetMinimal()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(US_WidgetMinimal);
	UClass* Z_Construct_UClass_US_WidgetMinimal_NoRegister()
	{
		return US_WidgetMinimal::StaticClass();
	}
	struct Z_Construct_UClass_US_WidgetMinimal_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_US_WidgetMinimal_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_Dunkaroos,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_US_WidgetMinimal_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "UI/S_WidgetMinimal.h" },
		{ "ModuleRelativePath", "UI/S_WidgetMinimal.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_US_WidgetMinimal_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<US_WidgetMinimal>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_US_WidgetMinimal_Statics::ClassParams = {
		&US_WidgetMinimal::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B000A0u,
		METADATA_PARAMS(Z_Construct_UClass_US_WidgetMinimal_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_US_WidgetMinimal_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_US_WidgetMinimal()
	{
		if (!Z_Registration_Info_UClass_US_WidgetMinimal.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_US_WidgetMinimal.OuterSingleton, Z_Construct_UClass_US_WidgetMinimal_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_US_WidgetMinimal.OuterSingleton;
	}
	template<> DUNKAROOS_API UClass* StaticClass<US_WidgetMinimal>()
	{
		return US_WidgetMinimal::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(US_WidgetMinimal);
	struct Z_CompiledInDeferFile_FID_Dunkaroos_Source_Dunkaroos_UI_S_WidgetMinimal_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Dunkaroos_Source_Dunkaroos_UI_S_WidgetMinimal_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_US_WidgetMinimal, US_WidgetMinimal::StaticClass, TEXT("US_WidgetMinimal"), &Z_Registration_Info_UClass_US_WidgetMinimal, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(US_WidgetMinimal), 3889011880U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Dunkaroos_Source_Dunkaroos_UI_S_WidgetMinimal_h_420485032(TEXT("/Script/Dunkaroos"),
		Z_CompiledInDeferFile_FID_Dunkaroos_Source_Dunkaroos_UI_S_WidgetMinimal_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Dunkaroos_Source_Dunkaroos_UI_S_WidgetMinimal_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
