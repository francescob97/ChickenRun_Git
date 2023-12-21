// Copyright Epic Games, Inc. All Rights Reserved.

#include "ChickenRunGameMode.h"
#include "ChickenRunCharacter.h"
#include "UObject/ConstructorHelpers.h"

AChickenRunGameMode::AChickenRunGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
