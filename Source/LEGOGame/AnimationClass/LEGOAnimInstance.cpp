// Fill out your copyright notice in the Description page of Project Settings.


#include "LEGOAnimInstance.h"

void ULEGOAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!OwnerCharacter)
	{
		OwnerCharacter=Cast<ALGCharacterBase>(TryGetPawnOwner());
		return ;
	}

	Speed = OwnerCharacter->GetVelocity().Size2D();
	FVector PlayerDir = OwnerCharacter->GetActorForwardVector();
	FVector MoveDir=OwnerCharacter->GetVelocity().GetSafeNormal();
	float P2M = FVector::DotProduct(PlayerDir,MoveDir);
	Direction=FMath::Acos(P2M)*180/3.14f;
	if (FVector::DotProduct(MoveDir,OwnerCharacter->GetActorRightVector())<0)
	{
		Direction*=-1;
	}
}
