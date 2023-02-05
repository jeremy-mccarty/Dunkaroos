// Fill out your copyright notice in the Description page of Project Settings.

// Initial includes
#include "UI/HUDs/D_HUD.h"

// Engine includes

// Game includes
#include "Core/D_GameInstance.h"
#include "Core/PlayerControllers/D_PlayerController.h"
#include "Utilities/BlueprintFunctionLibraries/D_WidgetUtilities.h"

void AD_HUD::BeginPlay()
{
	Super::BeginPlay();

	if (UD_GameInstance * gameInstance = UD_WidgetUtilities::GetGameInstance(GetOwningDunkaroosPlayerController()))
	{
		gameInstance->OnGlobalsDataLoaded.AddUniqueDynamic(this, &AD_HUD::HandleOnGlobalsLoaded);
		gameInstance->OnGlobalsDataReleased.AddUniqueDynamic(this, &AD_HUD::HandleOnGlobalsReleased);
	}
}

AD_PlayerController * AD_HUD::GetOwningDunkaroosPlayerController() const
{
	return Cast<AD_PlayerController>(GetOwningPlayerController());
}

void AD_HUD::HandleOnGlobalsLoaded(FName globalsName)
{
	HandleOnGlobalsLoaded_BP(globalsName);
}

void AD_HUD::HandleOnGlobalsReleased(FName globalsName)
{
	HandleOnGlobalsReleased_BP(globalsName);
}
