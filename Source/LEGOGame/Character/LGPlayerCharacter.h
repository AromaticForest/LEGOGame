// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "LGCharacterBase.h"

#include "LGPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
/**
 * 
 */
UCLASS()
class LEGOGAME_API ALGPlayerCharacter : public ALGCharacterBase
{
	GENERATED_BODY()
	public:
	ALGPlayerCharacter(const FObjectInitializer& Initializer);
	bool IsSprint();
	protected:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComponent;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	void MoveForward(float value);
	void MoveRight(float value);
	void Turn(float value);
	void LookUp(float value);
	void DoSprint();
	bool bSPrint;
};
