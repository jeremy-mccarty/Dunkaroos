// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Engine includes
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

// Game includes

// Must be last include
#include "D_GameInstance.generated.h"

UCLASS()
class DUNKAROOS_API UD_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<class UDataTable> DataTable;

	UFUNCTION(BlueprintCallable, Category = "Dunkaroos|Widget Utilities")
	class UD_GlobalsData * GetGlobalsData(const FName globalsName);

protected:
	UPROPERTY(EditAnywhere)
	TMap<FName, TSoftObjectPtr<class UD_GlobalsData>> GlobalsData;
};
