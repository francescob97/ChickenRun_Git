// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "PickableItem.generated.h"

/**
 * 
 */
UCLASS()
class CHICKENRUN_API APickableItem : public AItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void Pickup();
	
};
