// Fill out your copyright notice in the Description page of Project Settings.

// Initial include
#include "Core/D_GameInstance.h"

// Engine includes

// Game includes
#include "Core/DataTypes/D_UIDataTypes.h"

void UD_GameInstance::Init()
{
}

UD_GlobalsData * UD_GameInstance::GetGlobalsData(const FName globalsName)
{
	if (TSoftObjectPtr<UD_GlobalsData> * globalsData = GlobalsData.Find(globalsName))
	{
		if (globalsData->IsValid())
		{
			return globalsData->Get();
		}
		else if (!globalsData->IsNull())
		{
			return globalsData->LoadSynchronous();
		}
	}

	return nullptr;
}
