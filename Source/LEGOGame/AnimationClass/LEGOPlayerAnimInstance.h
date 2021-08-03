// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LEGOAnimInstance.h"
#include "LEGOPlayerAnimInstance.generated.h"

/**
 * 
 */
class ALGPlayerCharacter;
UCLASS()
class LEGOGAME_API ULEGOPlayerAnimInstance : public ULEGOAnimInstance
{
	GENERATED_BODY()
	protected:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	public:
	UPROPERTY()
	ALGPlayerCharacter* Player;

	UPROPERTY(BlueprintReadOnly)
	uint8 bSprint : 1;
};
