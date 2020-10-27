// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectFocusGameMode.h"
#include "ProjectFocusCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectFocusGameMode::AProjectFocusGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
