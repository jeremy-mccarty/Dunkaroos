// Fill out your copyright notice in the Description page of Project Settings.

// Initial includes
#include "Utilities/BlueprintFunctionLibraries/D_WidgetUtilities.h"

// Engine includes
#include "Engine/AssetManager.h"
#include "Engine/GameEngine.h"
#include "Engine/StreamableManager.h"
#include "Runtime/UMG/Public/UMG.h"

// Game includes
#include "Core/PlayerControllers/D_PlayerController.h"
#include "Core/DataTypes/D_UIDataTypes.h"
#include "Core/D_GameInstance.h"
#include "UI/Core/D_WidgetMinimal.h"

void UD_WidgetUtilities::PrintString(const FString & stringToPrint)
{
	if (GEngine != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.0f, FColor::Yellow, stringToPrint);
	}
}

UD_WidgetMinimal * UD_WidgetUtilities::CreateAndAddWidgetToViewport(TSubclassOf<class UD_WidgetMinimal> widgetClass, AD_PlayerController * owner, int32 zOrder/* = 0*/)
{
	if (owner != nullptr && IsValid(widgetClass))
	{
		if (UD_WidgetMinimal * result = CreateWidget<UD_WidgetMinimal>(owner, widgetClass))
		{
			result->AddToViewport(zOrder);
			return result;
		}
	}

	return nullptr;
}

UD_GameInstance * UD_WidgetUtilities::GetGameInstance(const UObject * worldContextObject)
{
	if (worldContextObject != nullptr)
	{
		if (const UWorld * world = worldContextObject->GetWorld())
		{
			return Cast<UD_GameInstance>(world->GetGameInstance());
		}
	}

	return nullptr;
}

UD_GlobalsData * UD_WidgetUtilities::GetGlobalsData(const UObject * worldContextObject, const FName globalsName)
{
	if (UD_GameInstance * gameInstance = GetGameInstance(worldContextObject))
	{
		return gameInstance->GetGlobalsData(globalsName);
	}

	return nullptr;
}

UD_WidgetMinimal * UD_WidgetUtilities::LoadScreen(const FName namedScreen, AD_PlayerController * owner, int32 zOrder)
{
	UD_WidgetMinimal * result = nullptr;
	
	if (const UD_GameInstance * gameInstance = GetGameInstance(owner))
	{
		for (const TPair<FName, UD_GlobalsData *> & pair : gameInstance->GetLoadedGlobals())
		{
			if (UD_GlobalsData * globalsData = pair.Value)
			{
				if (const TSubclassOf<UD_WidgetMinimal> * screen = globalsData->GetScreen(namedScreen))
				{
					result = CreateAndAddWidgetToViewport(*screen, owner, zOrder);
					break;
				}
			}
		}
	}

	if (result == nullptr)
	{
		// Log an error?
	}
	
	return result;
}