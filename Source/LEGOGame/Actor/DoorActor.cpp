// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "LEGOGame/Character/LGPlayerCharacter.h"

// Sets default values
ADoorActor::ADoorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent=CreateDefaultSubobject<USceneComponent>("Root");
	DoorRootCompoent=CreateDefaultSubobject<USceneComponent>("DoorRoot");
	DoorRootCompoent->SetupAttachment(RootComponent);
	DoorMeshRender=CreateDefaultSubobject<UStaticMeshComponent>("DoorRender");
	DoorMeshRender->SetupAttachment(DoorRootCompoent);
	BoxTrigger=CreateDefaultSubobject<UBoxComponent>("BoxTrigger");
	BoxTrigger->SetupAttachment(RootComponent);
	BoxTrigger->SetCollisionProfileName("OverlapAll");
	BoxTrigger->OnComponentBeginOverlap.AddDynamic(this,&ADoorActor::OnOverlayBegin);
	BoxTrigger->OnComponentEndOverlap.AddDynamic(this,&ADoorActor::OnOverlapEnd);
	
	
}

// Called when the game starts or when spawned
void ADoorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADoorActor::OnOverlayBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("Open"));
	if (ALGCharacterBase* Player = Cast<ALGCharacterBase>(OtherActor))
	{
		FVector D2P = (Player->GetActorLocation()-GetActorLocation()).GetSafeNormal();
		if (FVector::DotProduct(D2P,GetActorRightVector())>0)
		{
			OpenDir=-1;
		}
		else
		{
			OpenDir=1;
		}
		OpenDoor();
	}
	
}

void ADoorActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Log, TEXT("Close"));
	if (ALGCharacterBase* Player = Cast<ALGCharacterBase>(OtherActor))
	{
		CloseDoor();
	}
}

// Called every frame
void ADoorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

