// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Engine includes
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

// Game includes

// Must be last include
#include "D_HUD.generated.h"

UCLASS(BlueprintType, DisplayName = "Dunkaroos HUD")
class DUNKAROOS_API AD_HUD : public AHUD
{
	GENERATED_BODY()

	// -- C++ public interface
public:
	virtual void BeginPlay() override;

	// -- Blueprint protected interface
protected:
	// Returns the player controller cast to the dunkaroos base class
	UFUNCTION(BlueprintPure, Category = "Dunkaroos|UI")
	class AD_PlayerController * GetOwningDunkaroosPlayerController() const;
	
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName = "OnGlobalsLoaded"))
	void HandleOnGlobalsLoaded_BP(FName globalsName);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName = "OnGlobalsReleased"))
	void HandleOnGlobalsReleased_BP(FName globalsName);

	// -- C++ private interface
private:
	UFUNCTION()
	void HandleOnGlobalsLoaded(FName globalsName);
	
	UFUNCTION()
	void HandleOnGlobalsReleased(FName globalsName);
};
