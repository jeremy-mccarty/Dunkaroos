// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Engine includes
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

// Game includes

// Must be last include
#include "S_WidgetMinimal.generated.h"

UCLASS(BlueprintType, DisplayName = "WidgetMinimal")
class DUNKAROOS_API US_WidgetMinimal : public UUserWidget
{
	GENERATED_BODY()

	// -- C++ public interface
public:
	virtual void NativeConstruct() override;

	// -- Blueprint public interface
public:
};
