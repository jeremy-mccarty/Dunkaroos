// Fill out your copyright notice in the Description page of Project Settings.

// Initial includes
#include "UI/HUDs/D_HUD.h"

// Engine includes

// Game includes
#include "Core/PlayerControllers/D_PlayerController.h"

AD_PlayerController * AD_HUD::GetOwningDunkaroosPlayerController() const
{
	return Cast<AD_PlayerController>(GetOwningPlayerController());
}
