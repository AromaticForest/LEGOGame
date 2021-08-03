// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "LEGOGame/Character/LGCharacterBase.h"

#include "LEGOAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class LEGOGAME_API ULEGOAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	protected:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	UPROPERTY(BlueprintReadOnly)
	float Speed;
	UPROPERTY(BlueprintReadOnly)
	float Direction;
	UPROPERTY()
	ALGCharacterBase* OwnerCharacter;
	
};
