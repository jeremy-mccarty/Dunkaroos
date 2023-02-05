// Fill out your copyright notice in the Description page of Project Settings.

// Initial includes
#include "UI/Core/D_WidgetMinimal.h"

// Engine includes

// Game includes
#include "Core/D_GameInstance.h"
#include "Core/DataTypes/D_UIDataTypes.h"
#include "Core/PlayerControllers/D_PlayerController.h"
#include "Internationalization/StringTable.h"
#include "Utilities/BlueprintFunctionLibraries/D_WidgetUtilities.h"

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
	const AD_PlayerController * playerController = GetOwningDunkaroosPlayerController();
	return playerController != nullptr ? playerController->GetDunkaroosHUD() : nullptr;
}

UD_GameInstance* UD_WidgetMinimal::GetDunkaroosGameInstance()
{
	return Cast<UD_GameInstance>(GetGameInstance());
}

FLinearColor UD_WidgetMinimal::GetSafeColor(const FName colorId, TEnumAsByte<UD_ColorMode::Type> colorMode)
{
	FD_SafeColor foundColor = FD_SafeColor::Debug;

	// Unlike other globals data properties, safe colors are only stored in the core globals asset
	if (const UD_CoreGlobalsData * coreGlobals = GetCoreGlobalsData())
	{
		if (const UDataTable * dataTable = coreGlobals->SafeColors)
		{
			if (const FD_SafeColor * safeColor = dataTable->FindRow<FD_SafeColor>(colorId, TEXT("UD_WidgetMinimal::GetSafeColor")))
			{
				foundColor = *safeColor;
			}
		}
	}

	return foundColor.GetLinearColor(colorMode);
}

FText UD_WidgetMinimal::GetLocalizedText(const FName textId)
{
	FText result = FText::GetEmpty();
	
	// Unlike other globals data properties, localized text only stored in the core globals asset
	if (const UD_CoreGlobalsData * coreGlobals = GetCoreGlobalsData())
	{
		if (const UStringTable * stringTable = coreGlobals->StringTable)
		{
			result = FText::FromStringTable(stringTable->GetStringTableId(), textId.ToString());
		}
	}

	return result;
}

static const FName k_coreId = FName("Core");
UD_CoreGlobalsData* UD_WidgetMinimal::GetCoreGlobalsData()
{
	UD_CoreGlobalsData * result = nullptr;
	
	if (const UD_GameInstance * gameInstance = GetDunkaroosGameInstance())
	{
		const TMap<FName, UD_GlobalsData *> & loadedGlobals = gameInstance->GetLoadedGlobals();
		result = Cast<UD_CoreGlobalsData>(loadedGlobals.FindChecked(k_coreId));
	}

	return result;
}
