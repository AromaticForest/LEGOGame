// Fill out your copyright notice in the Description page of Project Settings.


#include "LGCharacterBase.h"

// Sets default values
ALGCharacterBase::ALGCharacterBase(const FObjectInitializer& Initializer):Super(Initializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALGCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALGCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALGCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

