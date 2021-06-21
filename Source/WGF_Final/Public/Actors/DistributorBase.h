// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DistributorBase.generated.h"

class APickupBase;

UCLASS()
class WGF_FINAL_API ADistributorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADistributorBase();

	UPROPERTY(BlueprintReadWrite)
	bool bIsOccupied;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Distributor", meta = (DisplayName = "Spawn Pickup", ReturnDisplayName = "Spawned Pickup"))
	APickupBase* SpawnPickup(float DeltaTime);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
