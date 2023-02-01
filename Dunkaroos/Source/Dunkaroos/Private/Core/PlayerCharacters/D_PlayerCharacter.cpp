// Fill out your copyright notice in the Description page of Project Settings.

// Initial include
#include "Core/PlayerCharacters/D_PlayerCharacter.h"

// Engine includes
#include "GameFramework/CharacterMovementComponent.h"

// Game includes


AD_PlayerCharacter::AD_PlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AD_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AD_PlayerCharacter::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

}

void AD_PlayerCharacter::SetupPlayerInputComponent(UInputComponent * playerInputComponent)
{
	Super::SetupPlayerInputComponent(playerInputComponent);
	check(playerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &AD_PlayerCharacter::MoveForward);
	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AD_PlayerCharacter::Jump);
}

void AD_PlayerCharacter::AddMovementInput(FVector worldDirection, float scaleValue, bool bForce)
{
	Super::AddMovementInput(worldDirection, scaleValue, bForce);
}

void AD_PlayerCharacter::Jump()
{
	Super::Jump();
}

void AD_PlayerCharacter::MoveForward(float axisValue)
{
	if (Controller != nullptr && axisValue != 0.0f)
	{
		FRotator rotation = Controller->GetControlRotation();
		UCharacterMovementComponent * characterMovement = GetCharacterMovement();
		if (characterMovement->IsMovingOnGround() || characterMovement->IsFalling())
		{
			rotation.Pitch = 0.0f;
		}

		const FVector direction = FRotationMatrix(rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(direction, axisValue);
	}
}