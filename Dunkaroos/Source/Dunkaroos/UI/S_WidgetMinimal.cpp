// Fill out your copyright notice in the Description page of Project Settings.

// Initial includes
#include "S_WidgetMinimal.h"

// Engine includes

// Game includes
#include <Dunkaroos/BlueprintFunctionLibraries/S_WidgetUtilities.h>

void US_WidgetMinimal::NativeConstruct()
{
	Super::NativeConstruct();
	US_WidgetUtilities::PrintString(FString(TEXT("NativeConstruct")));
}
