// Fill out your copyright notice in the Description page of Project Settings.

// Initial includes
#include "S_WidgetUtilities.h"

// Engine includes
#include <Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h>

// Game includes

void US_WidgetUtilities::PrintString(const FString & stringToPrint)
{
	if (GEngine != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.0f, FColor::Yellow, stringToPrint);
	}
}
