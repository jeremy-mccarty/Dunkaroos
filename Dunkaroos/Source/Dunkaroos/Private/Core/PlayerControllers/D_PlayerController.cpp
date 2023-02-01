// Fill out your copyright notice in the Description page of Project Settings.

// Initial includes
#include "Core/PlayerControllers/D_PlayerController.h"

// Engine includes

// Game includes
#include "UI/HUDs/D_HUD.h"

AD_HUD * AD_PlayerController::GetDunkaroosHUD() const
{
	return Cast<AD_HUD>(GetHUD());
}