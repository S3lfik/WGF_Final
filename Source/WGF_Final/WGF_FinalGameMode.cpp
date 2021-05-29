// Copyright Epic Games, Inc. All Rights Reserved.

#include "WGF_FinalGameMode.h"
#include "WGF_FinalCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWGF_FinalGameMode::AWGF_FinalGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
