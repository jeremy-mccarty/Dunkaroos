// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Engine includes
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

// Game includes

// Must be last include
#include "S_WidgetUtilities.generated.h"

UCLASS()
class DUNKAROOS_API US_WidgetUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	// -- C++ public interface
public:
	// Helper to print a simple string to the screen in yellow for 2 seconds
	static void PrintString(const FString & stringToPrint);
};
