// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CkrunCharacterBase.generated.h"

UCLASS()
class CHICKENRUN_API ACkrunCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACkrunCharacterBase();

protected:	
	virtual void BeginPlay() override;	

};
