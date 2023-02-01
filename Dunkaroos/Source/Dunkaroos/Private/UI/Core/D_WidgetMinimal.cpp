// Fill out your copyright notice in the Description page of Project Settings.

// Initial includes
#include "UI/Core/D_WidgetMinimal.h"

// Engine includes

// Game includes
#include "Utilities/BlueprintFunctionLibraries/D_WidgetUtilities.h"
#include "Core/PlayerControllers/D_PlayerController.h"

void UD_WidgetMinimal::NativeConstruct()
{
	Super::NativeConstruct();
	UD_WidgetUtilities::PrintString(FString(TEXT("NativeConstruct")));
}

AD_PlayerController * UD_WidgetMinimal::GetOwningDunkaroosPlayerController() const
{
	return Cast<AD_PlayerController>(GetOwningPlayer());
}

AD_HUD * UD_WidgetMinimal::GetDunkaroosHUD() const
{
	AD_PlayerController * playerController = GetOwningDunkaroosPlayerController();
	return playerController != nullptr ? playerController->GetDunkaroosHUD() : nullptr;
}
