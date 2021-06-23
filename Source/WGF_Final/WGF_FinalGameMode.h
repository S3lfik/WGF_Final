// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Public/Actors/DistributorBase.h"
#include "WGF_FinalGameMode.generated.h"


UCLASS(minimalapi)
class AWGF_FinalGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AWGF_FinalGameMode();

protected:
	UFUNCTION(BlueprintCallable)
	ADistributorBase* GetRandomFreeDistributor(UPARAM(ref) TArray<ADistributorBase*>& InDistributors) const;
};



