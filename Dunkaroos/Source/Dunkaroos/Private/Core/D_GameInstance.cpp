// Fill out your copyright notice in the Description page of Project Settings.

// Initial include
#include "Core/D_GameInstance.h"

// Engine includes

// Game includes
#include "Core/DataTypes/D_UIDataTypes.h"

void UD_GameInstance::Init()
{
	Super::Init();
}

const TMap<FName, UD_GlobalsData*>& UD_GameInstance::GetLoadedGlobals() const
{
	return m_loadedGlobals;
}

bool UD_GameInstance::LoadGlobalsDataWithDelegate(const FName globalsName, TSoftObjectPtr<UD_GlobalsData> globalsData, FStreamableDelegate delegateToCall, TSharedPtr<FStreamableHandle> & outHandle)
{
	bool result = false;
	
	if (ValidateGlobalsDataPendingLoad(globalsName, globalsData))
	{
		outHandle = UAssetManager::GetStreamableManager().RequestAsyncLoad(globalsData.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &UD_GameInstance::HandleLoadedGlobalsData, globalsName, delegateToCall));
		result = outHandle.IsValid();
	}

	if (result)
	{
		// Log the handle in the pending globals map so we can cache it when it actually loads
		m_pendingGlobals.Add(globalsName, outHandle);
	}
	else
	{
		// Log an error?
	}
	
	return result;
}

UD_GlobalsData * UD_GameInstance::GetGlobalsData(const FName globalsName)
{
	if (UD_GlobalsData ** globalsData = m_loadedGlobals.Find(globalsName))
	{
		return *globalsData;
	}

	return nullptr;
}

bool UD_GameInstance::LoadGlobalsData(const FName globalsName, TSoftObjectPtr<UD_GlobalsData> globalsData)
{
	const FStreamableDelegate delegate;
	TSharedPtr<FStreamableHandle> handle;
	return LoadGlobalsDataWithDelegate(globalsName, globalsData, delegate, OUT handle);
}

void UD_GameInstance::ReleaseGlobalsData(const FName globalsName)
{
	if (UD_GlobalsData * globalsData = m_loadedGlobals.FindAndRemoveChecked(globalsName))
	{
		// TODO: Do we unload all screens and remove them from the viewport?
	}
	
	OnGlobalsDataReleased.Broadcast(globalsName);
}

bool UD_GameInstance::ValidateGlobalsDataPendingLoad(const FName globalsName, TSoftObjectPtr<UD_GlobalsData> globalsData) const
{
	return !globalsName.IsNone() && !m_loadedGlobals.Contains(globalsName) && globalsData.ToSoftObjectPath().IsValid();
}

void UD_GameInstance::HandleLoadedGlobalsData(const FName globalsName, FStreamableDelegate delegateToCall)
{
	const TSharedPtr<FStreamableHandle> handle = m_pendingGlobals.FindAndRemoveChecked(globalsName);
	if (handle.IsValid())
	{
		if (UD_GlobalsData * globalsData = Cast<UD_GlobalsData>(handle->GetLoadedAsset()))
		{
			m_loadedGlobals.Add(globalsName, globalsData);
			delegateToCall.ExecuteIfBound();
			OnGlobalsDataLoaded.Broadcast(globalsName);
		}
	}
}
