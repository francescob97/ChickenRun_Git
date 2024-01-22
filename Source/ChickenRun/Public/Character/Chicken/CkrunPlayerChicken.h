// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/Chicken/CkrunCharacterChicken.h"
#include "CkrunPlayerChicken.generated.h"

class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */


UCLASS()
class CHICKENRUN_API ACkrunPlayerChicken : public ACkrunCharacterChicken
{
	GENERATED_BODY()

public:
	ACkrunPlayerChicken();
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components")
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(EditDefaultsOnly, Category="Components")
	TObjectPtr<USpringArmComponent> CameraBoom;
	
};
