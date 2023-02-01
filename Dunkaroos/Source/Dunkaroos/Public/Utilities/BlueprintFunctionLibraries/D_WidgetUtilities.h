// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Engine includes
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

// Game includes

// Must be last include
#include "D_WidgetUtilities.generated.h"

UCLASS()
class DUNKAROOS_API UD_WidgetUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	// -- C++ public interface
public:
	// Helper to print a simple string to the screen in yellow for 2 seconds
	static void PrintString(const FString & stringToPrint);

	UFUNCTION(BlueprintCallable, Category = "Dunkaroos|Widget Utilities", meta = (AdvancedDisplay = "ZOrder"))
	static class UD_WidgetMinimal * CreateAndAddWidgetToViewport(TSubclassOf<class UD_WidgetMinimal> widgetClass, class AD_PlayerController * owner, int32 zOrder = 0);

	UFUNCTION(BlueprintCallable, Category = "Dunkaroos|Widget Utilities")
	static void LoadScreenReference(const FName screenName);

	UFUNCTION(BlueprintCallable, Category = "Dunkaroos|Widget Utilities", meta = (WorldContext = "worldContextObject"))
	static class UD_GameInstance * GetGameInstance(const class UObject * worldContextObject);

	UFUNCTION(BlueprintCallable, Category = "Dunkaroos|Widget Utilities", meta = (WorldContext = "worldContextObject"))
	static class UD_GlobalsData * GetGlobalsData(const class UObject * worldContextObject, const FName globalsName);

	UFUNCTION(BlueprintCallable, Category = "Dunkaroos|Widget Utilities", meta = (AdvancedDisplay = "ZOrder"))
	static class UD_WidgetMinimal * LoadScreen(const FName namedScreen, class AD_PlayerController * owner, int32 zOrder = 0);
};