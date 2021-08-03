// Fill out your copyright notice in the Description page of Project Settings.


#include "LGCharacterMovementComponent.h"

#include "LEGOGame/Character/LGPlayerCharacter.h"

float ULGCharacterMovementComponent::GetMaxSpeed() const
{
	float Speed=Super::GetMaxSpeed();
	if (ALGPlayerCharacter* Player = Cast<ALGPlayerCharacter>(GetOwner()))
	{
		if (Player->IsSprint())
		{
			Speed*=3;
		}
	}
	return Speed;
}
