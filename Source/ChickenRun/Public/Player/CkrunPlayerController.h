// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CkrunPlayerController.generated.h"

class ACkrunCharacterChicken;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class CHICKENRUN_API ACkrunPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ACkrunPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	/*
	 * Inputs
	 */
	
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> CkrunContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> LookAction;
	
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> CrouchAction;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> ToggleInventoryhAction;
	
	ACkrunCharacterChicken* PlayerCharacter;

	UPROPERTY(EditAnywhere, Category="Input")
	float LookSensitivity = 1.f;

	/*
	 *  Inventory 
	 */		

	UPROPERTY(EditAnywhere, Category="Inventory")
	TSubclassOf<UUserWidget> InventoryMenuHUDClass;

	UPROPERTY()
	TObjectPtr<UUserWidget> InventoryMenuHUD;
	
	UPROPERTY(EditAnywhere, Category="Inventory")
	int32 InventorySlots;
	
		
	void Move(const FInputActionValue& InputActionValue);
	void Look(const FInputActionValue& InputActionValue);
	void Jump();
	void Crouch();
	void ToggleInventory();

public:
	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetInventorySlots() const {return InventorySlots; };
	
};
