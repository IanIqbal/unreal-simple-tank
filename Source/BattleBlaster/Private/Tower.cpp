// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

ATower::ATower() {

}

void ATower::BeginPlay() {
	Super::BeginPlay();
}

void ATower::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	float PlayerDist = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());

	if (PlayerDist <= DetectRange) {
		RotateTurret(Tank->GetActorLocation());
	}
}

