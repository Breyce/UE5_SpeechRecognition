// Copyright Epic Games, Inc. All Rights Reserved.

#include "JarvisGameMode.h"
#include "JarvisCharacter.h"
#include "UObject/ConstructorHelpers.h"

AJarvisGameMode::AJarvisGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
