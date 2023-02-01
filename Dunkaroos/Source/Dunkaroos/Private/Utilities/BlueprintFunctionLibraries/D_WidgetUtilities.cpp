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
		UD_WidgetMinimal * result = CreateWidget<UD_WidgetMinimal>(owner, widgetClass);
		result->AddToViewport(zOrder);
		return result;
	}

	return nullptr;
}

void UD_WidgetUtilities::LoadScreenReference(const FName screenName)
{
	if (UAssetManager * assetManager = UAssetManager::GetIfValid())
	{
		//FD_ScreenReferences * item;
		//FStreamableManager & streamableManager = assetManager->GetStreamableManager();
		//streamableManager.RequestAsyncLoad(
		//	item->Screen.ToSoftObjectPath(),
		//	FStreamableDelegate::CreateLambda([]()
		//	{

		//	}));
	}
	TArray<FSoftObjectPath> array;
	FStreamableManager streamableManager;
	streamableManager.RequestAsyncLoad(array);
	//FStreamableManager::RequestAsyncLoad(array);
	//world->GetStreama

	//// Getting our StreamableManager
	//StreamableManager.RequestAsyncLoad(ToStream,
	//	FStreamableDelegate::CreateUObject(this,
	//		UMyStreamExample::OnAssetsLoaded
	//	)
	//);
}

UD_GameInstance * UD_WidgetUtilities::GetGameInstance(const UObject * worldContextObject)
{
	if (worldContextObject != nullptr)
	{
		if (UWorld * world = worldContextObject->GetWorld())
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
	if (UD_GlobalsData * globalsData = GetGlobalsData(owner, FName("Core")))
	{
		if (TSubclassOf<UD_WidgetMinimal> * screen = globalsData->NamedScreens.Find(namedScreen))
		{
			return CreateAndAddWidgetToViewport(*screen, owner, zOrder);
		}
	}

	return nullptr;
}
