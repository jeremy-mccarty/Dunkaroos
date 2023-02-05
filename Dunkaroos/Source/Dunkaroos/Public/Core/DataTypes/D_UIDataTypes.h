// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Engine includes
#include "CoreMinimal.h"
#include "Engine/DataTable.h"

// Game includes
#include "D_UIEnums.h"

// Must be last include
#include "D_UIDataTypes.generated.h"

UCLASS(Category = "Dunkaroos|Data Types", DisplayName = "Dunkaroos Global Data")
class UD_GlobalsData : public UDataAsset
{
	GENERATED_BODY()

	// -- C++ public interface
public:
	// Returns the subclass of a screen by name
	TSubclassOf<class UD_WidgetMinimal> * GetScreen(const FName screenName) { return NamedScreens.Find(screenName); }
	
	// -- Blueprint public interface
public:
	// TODO This should be TAssetSubclassOf
	UPROPERTY(EditAnywhere, Category = "Dunkaroos")
	TMap<FName, TSubclassOf<class UD_WidgetMinimal>> NamedScreens;

	// TODO: Should this be TSoftObjectPtr
	UPROPERTY(EditAnywhere, Category = "Dunkaroos")
	class UDataTable * SafeColors;
};

USTRUCT(Category = "Dunkaroos|Data Types", DisplayName = "Dunkaroos Color")
struct FD_SafeColor : public FTableRowBase
{
	GENERATED_BODY()

	// -- C++ public interface:
public:
	FD_SafeColor() { };
	FD_SafeColor(FLinearColor normal, FLinearColor protanopia, FLinearColor deuteranopia, FLinearColor tritanopia)
	{
		Values[UD_ColorMode::Normal] = normal;
		Values[UD_ColorMode::Protanopia] = protanopia;
		Values[UD_ColorMode::Deuteranopia] = deuteranopia;
		Values[UD_ColorMode::Tritanopia] = tritanopia;
	};

	FLinearColor GetLinearColor(UD_ColorMode::Type colorMode) const { return Values[colorMode]; }

	// -- Blueprint public interface
public:
	UPROPERTY(EditAnywhere, Category = "Dunkaroos")
	FString Description;
	
	UPROPERTY(EditAnywhere, Category = "Dunkaroos")
	FLinearColor Values[UD_ColorMode::Count];

	// Global default colors
	static DUNKAROOS_API const FD_SafeColor Red;
	static DUNKAROOS_API const FD_SafeColor Green;
	static DUNKAROOS_API const FD_SafeColor Blue;
	static DUNKAROOS_API const FD_SafeColor Yellow;
	static DUNKAROOS_API const FD_SafeColor Debug;
};