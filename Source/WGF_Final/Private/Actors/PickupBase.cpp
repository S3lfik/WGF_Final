// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/PickupBase.h"
#include <Components/StaticMeshComponent.h>

// Sets default values
APickupBase::APickupBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshComp;
}

// Called when the game starts or when spawned
void APickupBase::BeginPlay()
{
	Super::BeginPlay();

	DetonationTimeCurr = DetonationTimeMax;
	MeshMatInstance = MeshComp->CreateAndSetMaterialInstanceDynamicFromMaterial(0, MeshComp->GetMaterial(0));
	MeshMatInstance->SetVectorParameterValue(FName("Color"), FLinearColor::Red);
}

void APickupBase::UpdateDetonationTime(float DeltaTime)
{
	DetonationTimeCurr -= DeltaTime;
}

// Called every frame
void APickupBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateDetonationTime(DeltaTime);

}

