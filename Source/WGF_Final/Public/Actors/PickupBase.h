// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupBase.generated.h"

UCLASS()
class WGF_FINAL_API APickupBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UMaterialInstanceDynamic* MeshMatInstance;

	UPROPERTY(VisibleDefaultsOnly, Category = "Logic")
	float DetonationTimeMax = 5.f;

	float DetonationTimeCurr;

	void UpdateDetonationTime(float DeltaTime);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
