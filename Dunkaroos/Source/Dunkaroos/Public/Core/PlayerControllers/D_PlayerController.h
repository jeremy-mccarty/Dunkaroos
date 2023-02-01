// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Engine includes
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

// Game includes

// Must be last include
#include "D_PlayerController.generated.h"

UCLASS(BlueprintType, DisplayName = "Dunkaroos Player Controller", ClassGroup = "Dunkaroos")
class DUNKAROOS_API AD_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "Dunkaroos|Player Controller")
	class AD_HUD * GetDunkaroosHUD() const;
};
