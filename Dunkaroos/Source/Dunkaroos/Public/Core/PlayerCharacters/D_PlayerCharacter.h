// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Engine includes
#include "CoreMinimal.h"
#include "GameFramework/Character.h"

// Game includes

// Must be last include
#include "D_PlayerCharacter.generated.h"

UCLASS()
class DUNKAROOS_API AD_PlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AD_PlayerCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float deltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent * playerInputComponent) override;
	virtual void AddMovementInput(FVector worldDirection, float scaleValue = 1.0f, bool bForce = false) override;
	virtual void Jump() override;

private:
	void MoveForward(float axisValue);
};
