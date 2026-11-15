// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BattleBlasterGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class BATTLEBLASTER_API UBattleBlasterGameInstance : public UGameInstance
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere);
	int32 CurrentLevel = 1;

	UPROPERTY(EditAnywhere);
	int32 LastLevel = 3;
	
};
