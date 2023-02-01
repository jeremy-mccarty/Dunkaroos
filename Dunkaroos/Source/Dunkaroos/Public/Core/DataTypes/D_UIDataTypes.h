// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Engine includes
#include "CoreMinimal.h"
#include "Engine/DataTable.h"

// Game includes

// Must be last include
#include "D_UIDataTypes.generated.h"

USTRUCT(Category = "Dunkaroos|Data Types", DisplayName = "Dunkaroos Screen References")
struct FD_ScreenReferences : public FTableRowBase
{
	GENERATED_BODY()

	// -- Public interface
public:
	// The screen name used to tie a screen to a class
	UPROPERTY(EditAnywhere, Category = "Dunkaroos")
	FName ScreenName;

	// TODO This should be TAssetSubclassOf
	UPROPERTY(EditAnywhere, Category = "Dunkaroos")
	TSubclassOf<class UD_WidgetMinimal> Screen;
};

UCLASS(Category = "Dunkaroos|Data Types", DisplayName = "Dunkaroos Global Data")
class UD_GlobalsData : public UDataAsset
{
	GENERATED_BODY()

	// -- Public interface
public:
	// TODO This should be TAssetSubclassOf
	UPROPERTY(EditAnywhere, Category = "Dunkaroos")
	TMap <FName, TSubclassOf<class UD_WidgetMinimal>> NamedScreens;
};