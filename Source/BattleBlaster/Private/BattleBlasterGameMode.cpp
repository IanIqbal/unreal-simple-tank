// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleBlasterGameMode.h"

#include "AnalyticsPropertyStore.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "BattleBlasterGameInstance.h"
#include "Tower.h"

void ABattleBlasterGameMode::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> Towers;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATower::StaticClass(), Towers);

	TowersCount = Towers.Num();
	UE_LOG(LogTemp, Display, TEXT("Total towers: %d"), TowersCount);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (PlayerPawn)
	{
		Tank = Cast<ATank>(PlayerPawn);

		if (!Tank)
		{
			UE_LOG(LogTemp, Display, TEXT("Gamemode: Failed to find tank actor"));
		}
	}

	int32 indexLoop = 0;

	while (indexLoop < TowersCount)
	{
		if (Tank && Towers[indexLoop])
		{
			ATower* Tower = Cast<ATower>(Towers[indexLoop]);

			if (Tower)
			{
				Tower->Tank = Tank;
				UE_LOG(LogTemp, Display, TEXT("%s setting the tank variable on each tower"),
				       *Tower->GetActorNameOrLabel());
			}
		}

		indexLoop++;
	}

	CountdownSeconds = CountdownDelay;
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ABattleBlasterGameMode::OnCountdownTimerTimeout, 1.0f, true);

}

void ABattleBlasterGameMode::ActorDied(AActor* DeadActor)
{

	bool IsGameOver = false;
	
	if (DeadActor == Tank)
	{
		Tank->HandleDestruction();
		IsGameOver = true;
	}
	else
	{
		ATower* DeadTower = Cast<ATower>(DeadActor);
		if (DeadTower)
		{
			
			DeadTower->HandleDestruction();

			TowersCount--;

			if(TowersCount <= 0)
			{
				IsGameOver = true;
				IsVictory = true;
				UE_LOG(LogTemp, Display, TEXT("Victory"));
			}
		}
	}

	if (IsGameOver) {
		FString GameOverMessage = IsVictory? "You Win!" : "Defeat!";
		UE_LOG(LogTemp, Display, TEXT("Game over: %s"), *GameOverMessage);

		FTimerHandle GameOverTimerHandle;
		GetWorldTimerManager().SetTimer(GameOverTimerHandle, this, &ABattleBlasterGameMode::OnGameOver, GameOverDelay, true);

	}

	
}

void ABattleBlasterGameMode::OnGameOver()
{
	UGameInstance* GameInstance = GetGameInstance();

	if (GameInstance) {
		UBattleBlasterGameInstance* BattleBlasterGameInstance = Cast<UBattleBlasterGameInstance>(GameInstance);

		if (BattleBlasterGameInstance) {
			if (IsVictory) {
				BattleBlasterGameInstance->LoadNextLevel();
			}
			else {
				BattleBlasterGameInstance->RestartCurrentLevel();
			}
		}
	}
}

void ABattleBlasterGameMode::OnCountdownTimerTimeout()
{
	CountdownSeconds -= 1;

	if (CountdownSeconds > 0)
	{
		UE_LOG(LogTemp, Display, TEXT("Countdown: %d"), CountdownSeconds);
	}
	else if (CountdownSeconds == 0)
	{
		UE_LOG(LogTemp, Display, TEXT("Go!"));
		Tank->SetPlayerControl(true);
	}
	else
	{
		// CountdownSeconds is less than 0
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		UE_LOG(LogTemp, Display, TEXT("Clear timer"));
	}

}
