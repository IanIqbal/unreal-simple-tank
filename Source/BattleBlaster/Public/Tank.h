// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"

#include "GameFramework/SpringArmComponent.h"

#include "EnhancedInputSubsystems.h"

#include "InputAction.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "Tank.generated.h"


class UInputMappingContext;
	class UCameraComponent;
/**
 * 
 */
UCLASS()
class BATTLEBLASTER_API ATank : public ABasePawn
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:
	ATank();
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category="Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere,Category="Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* TurnAction;

	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* FireAction;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere)
	float TankSpeed;

	UPROPERTY(EditAnywhere)
	float TankTurnSpeed;

	APlayerController* PlayerController;
	bool IsAlive = true;
	void MoveInput(const FInputActionValue& Value);
	void TurnInput(const FInputActionValue& Value);

	void HandleDestruction();
	void SetPlayerControl(bool status);

};
