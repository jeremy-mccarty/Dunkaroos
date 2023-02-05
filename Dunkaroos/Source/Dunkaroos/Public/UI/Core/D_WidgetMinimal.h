// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Engine includes
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

// Game includes

// Must be last include
#include "D_WidgetMinimal.generated.h"

UCLASS(Blueprintable, BlueprintType, DisplayName = "Dunkaroos Widget Minimal", ClassGroup = "Dunkaroos", HideDropdown)
class DUNKAROOS_API UD_WidgetMinimal : public UUserWidget
{
	GENERATED_BODY()

	// -- C++ public interface
public:
	// Overrides
	virtual void NativeConstruct() override;

	// -- Blueprint protected interface
protected:
	// Returns the player controller cast to the dunkaroos base class
	UFUNCTION(BlueprintPure, Category = "Dunkaroos|UI")
	class AD_PlayerController * GetOwningDunkaroosPlayerController() const;

	// Returns the hud cast to the dunkaroos base class
	UFUNCTION(BlueprintPure, Category = "Dunkaroos|UI")
	class AD_HUD * GetDunkaroosHUD() const;

	// Returns the game instance cast to the dunkaroos base class
	UFUNCTION(BlueprintCallable, Category = "Dunkaroos|UI")
	class UD_GameInstance * GetDunkaroosGameInstance();
};
