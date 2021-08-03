// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorActor.generated.h"


class UBoxComponent;
class UStaticMeshComponent;
UCLASS()
class LEGOGAME_API ADoorActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoorActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* DoorRootCompoent;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* DoorMeshRender;
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxTrigger;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintImplementableEvent)
	void OpenDoor();
	UFUNCTION(BlueprintImplementableEvent)
	void CloseDoor();
	UPROPERTY(BlueprintReadOnly)
	float OpenDir;
	UFUNCTION()
	void OnOverlayBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                    UPrimitiveComponent* OtherComp,
	                    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                  UPrimitiveComponent* OtherComp,
	                  int32 OtherBodyIndex);
};
