// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Engine includes
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/AssetManager.h"

// Game includes

// Must be last include
#include "D_GameInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FS_OnGlobalsDataChanged, FName, globalsName);

UCLASS()
class DUNKAROOS_API UD_GameInstance : public UGameInstance
{
	GENERATED_BODY()

	// -- C++ public interface
public:
	// Overrides
	virtual void Init() override;

	// Returns a reference to the globals that have been loaded
	const TMap<FName, class UD_GlobalsData *> & GetLoadedGlobals() const;

	bool LoadGlobalsDataWithDelegate(const FName globalsName, TSoftObjectPtr<UD_GlobalsData> globalsData, FStreamableDelegate delegateToCall, TSharedPtr<FStreamableHandle> & outHandle);

	// -- Blueprint public interface
public:
	UFUNCTION(BlueprintCallable, Category = "Dunkaroos|Game Instance")
	class UD_GlobalsData * GetGlobalsData(const FName globalsName);

	UFUNCTION(BlueprintCallable, Category = "Dunkaroos|Game Instance")
	bool LoadGlobalsData(const FName globalsName, TSoftObjectPtr<UD_GlobalsData> globalsData);

	UFUNCTION(BlueprintCallable, Category = "Dunkaroos|Game Instance")
	void ReleaseGlobalsData(const FName globalsName);

	UPROPERTY(BlueprintAssignable, Category = "Dunkaroos|Game Instance|Delegates")
	FS_OnGlobalsDataChanged OnGlobalsDataLoaded;

	UPROPERTY(BlueprintAssignable, Category = "Dunkaroos|Game Instance|Delegates")
	FS_OnGlobalsDataChanged OnGlobalsDataReleased;

	// -- C++ private interface
private:
	// Globals that get loaded by loadGlobalsData and released by releaseGlobalsData
	UPROPERTY()
	TMap<FName, class UD_GlobalsData *> m_loadedGlobals;

	// Globals that are currently being loaded
	TMap<FName, TSharedPtr<FStreamableHandle>> m_pendingGlobals;
	
	bool ValidateGlobalsDataPendingLoad(const FName globalsName, TSoftObjectPtr<UD_GlobalsData> globalsData) const;

	void HandleLoadedGlobalsData(const FName globalsName, FStreamableDelegate delegateToCall);
};
