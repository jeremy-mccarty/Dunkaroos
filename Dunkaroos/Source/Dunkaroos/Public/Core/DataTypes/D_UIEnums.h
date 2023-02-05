// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Engine includes
#include "CoreMinimal.h"

// Game includes

// Must be last include
#include "D_UIEnums.generated.h"

UENUM(BlueprintType)
namespace UD_ColorMode
{
	enum Type
	{
		Normal,
		Protanopia,
		Deuteranopia,
		Tritanopia,
		Count UMETA(Hidden)
	};
}