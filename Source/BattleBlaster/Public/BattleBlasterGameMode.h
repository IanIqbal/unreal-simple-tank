// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Tank.h"
#include "BattleBlasterGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BATTLEBLASTER_API ABattleBlasterGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	public:
	
		virtual void BeginPlay () override;

		ATank* Tank;
		int32 TowersCount;
		float GameOverDelay = 3.0f;
		UPROPERTY(EditAnywhere)
		int32 CountdownDelay = 3;

		int32 CountdownSeconds;

		FTimerHandle CountdownTimerHandle;

		bool IsVictory = false;
	void ActorDied(AActor* DeadActor);
	void OnGameOver();
	void OnCountdownTimerTimeout();

};
