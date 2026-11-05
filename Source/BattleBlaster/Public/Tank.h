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

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere)
	float TankSpeed;

	void MoveInput(const FInputActionValue& Value);
};
