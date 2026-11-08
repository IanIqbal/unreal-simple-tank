// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleBlasterGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tower.h"
void ABattleBlasterGameMode::BeginPlay() {
	Super::BeginPlay();

	TArray <AActor*> Towers;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATower::StaticClass(), Towers);

	TowersCount = Towers.Num();
	UE_LOG(LogTemp, Display, TEXT("Total towers: %d"), TowersCount);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (PlayerPawn) {
		Tank = Cast<ATank>(PlayerPawn);

		if (!Tank) {
			UE_LOG(LogTemp, Display, TEXT("Gamemode: Failed to find tank actor"));
		}
	}

	int32 indexLoop = 0;

	while (indexLoop < TowersCount) {

		if (Tank && Towers[indexLoop]) {
			
			ATower* Tower = Cast<ATower>(Towers[indexLoop]);
			
			if (Tower) {
				Tower->Tank = Tank;
				UE_LOG(LogTemp, Display, TEXT("%s setting the tank variable on each tower"), *Tower->GetActorNameOrLabel());
			}
		}

		indexLoop++;
	}
}