// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleBlasterGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UBattleBlasterGameInstance::LoadLevel(int32 Level)
{

	if (Level > 0 && Level <= LastLevel) {
		CurrentLevel = Level;

		FString TargetLevel = FString::Printf(TEXT("Level_%d"), CurrentLevel);
		UGameplayStatics::OpenLevel(GetWorld(), *TargetLevel);
	}
}

void UBattleBlasterGameInstance::RestartCurrentLevel()
{
	LoadLevel(CurrentLevel);
}

void UBattleBlasterGameInstance::RestartGame()
{
	LoadLevel(1);
}

void UBattleBlasterGameInstance::LoadNextLevel()
{

	if (CurrentLevel < LastLevel) {

	LoadLevel(CurrentLevel+1);
	}
	else {
		RestartGame();
	}
}
