// Fill out your copyright notice in the Description page of Project Settings.


#include "LEGOPlayerAnimInstance.h"

#include "LEGOGame/Character/LGPlayerCharacter.h"

void ULEGOPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (!Player)
	{
		Player = Cast<ALGPlayerCharacter>(TryGetPawnOwner());
		return ;
	}
	bSprint=Player->IsSprint();
}
