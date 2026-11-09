// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

ATower::ATower() {

}

void ATower::BeginPlay() {
	Super::BeginPlay();

	FTimerHandle FireTimerHandle;
	GetWorldTimerManager().SetTimer(FireTimerHandle, this, &ATower::Fire, FireRate, true);
}

void ATower::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);


	if (IsInFireRange()) {
		RotateTurret(Tank->GetActorLocation());
	}
}

void ATower::CheckFire() {

	if (Tank && IsInFireRange()) {
		Fire();
	}
}

bool ATower::IsInFireRange()
{
	bool UnderFireRange = false;

	float PlayerDist = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
	if (PlayerDist <= DetectRange) {
		UnderFireRange = true;
	}
	return UnderFireRange;
}

