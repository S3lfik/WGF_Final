// Copyright Epic Games, Inc. All Rights Reserved.

#include "WGF_FinalGameMode.h"
#include "WGF_FinalCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWGF_FinalGameMode::AWGF_FinalGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

ADistributorBase* AWGF_FinalGameMode::GetRandomFreeDistributor(UPARAM(ref) TArray<ADistributorBase*>& InDistributors) const
{
	if (InDistributors.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("InDistributors is empty"));
		return nullptr;
	}

	for (const auto distrib : InDistributors)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s occupation is : %s"), *distrib->GetFName().ToString(), distrib->bIsOccupied ? TEXT("True") : TEXT("False"));
	}

	auto FreeDistribs = InDistributors.FilterByPredicate([](const ADistributorBase* Distrib)
	{
		return !Distrib->bIsOccupied;
	});

	auto randIndex = FMath::RandRange(0, FreeDistribs.Num() - 1);

	ADistributorBase* ret = FreeDistribs.Num() > 0 ? FreeDistribs[randIndex] : nullptr;
	
	return ret;
}