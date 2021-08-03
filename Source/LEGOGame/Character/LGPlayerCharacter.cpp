// Fill out your copyright notice in the Description page of Project Settings.


#include "LGPlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "LEGOGame/Components/LGCharacterMovementComponent.h"

ALGPlayerCharacter::ALGPlayerCharacter(const FObjectInitializer& Initializer)
	:Super(Initializer.SetDefaultSubobjectClass<ULGCharacterMovementComponent>(CharacterMovementComponentName))
{
	SpringArmComponent=CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	CameraComponent=CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
	SpringArmComponent->SetupAttachment(RootComponent);
}

bool ALGPlayerCharacter::IsSprint()
{
	return bSPrint;
}

void ALGPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward",this,&ALGPlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight",this,&ALGPlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn",this,&ALGPlayerCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp",this,&ALGPlayerCharacter::LookUp);
	PlayerInputComponent->BindAction("DoSprint",IE_Pressed,this,&ALGPlayerCharacter::DoSprint);
	PlayerInputComponent->BindAction("DoSprint",IE_Released,this,&ALGPlayerCharacter::DoSprint);
}

void ALGPlayerCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(),value);
}

void ALGPlayerCharacter::MoveRight(float value)
{

	AddMovementInput(GetActorRightVector(),value);
}

void ALGPlayerCharacter::Turn(float value)
{
	AddControllerYawInput(value*GetWorld()->GetDeltaSeconds()*40);
}

void ALGPlayerCharacter::LookUp(float value)
{
	AddControllerPitchInput(value*GetWorld()->GetDeltaSeconds()*40);
}

void ALGPlayerCharacter::DoSprint()
{
	bSPrint=!bSPrint;
}
