// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/CkrunPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"
#include "Character/Chicken/CkrunCharacterChicken.h"

ACkrunPlayerController::ACkrunPlayerController()
{
	bReplicates = true;
}

void ACkrunPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(CkrunContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(CkrunContext, 0);


	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		PlayerCharacter = Cast<ACkrunCharacterChicken>(ControlledPawn);
	}
 
	/*bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);*/

	InventoryMenuHUD = CreateWidget<UUserWidget>(this, InventoryMenuHUDClass);
	InventoryMenuHUD->SetVisibility(ESlateVisibility::Collapsed);
	InventoryMenuHUD->AddToViewport();
}

void ACkrunPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACkrunPlayerController::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACkrunPlayerController::Look);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACkrunPlayerController::Jump);
	EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Triggered, this, &ACkrunPlayerController::Crouch);
	EnhancedInputComponent->BindAction(ToggleInventoryhAction, ETriggerEvent::Triggered, this, &ACkrunPlayerController::ToggleInventory);
	
}

void ACkrunPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (PlayerCharacter)
	{
		PlayerCharacter->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		PlayerCharacter->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void ACkrunPlayerController::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (PlayerCharacter)
	{
		PlayerCharacter->AddControllerPitchInput(-LookAxisVector.Y);
		PlayerCharacter->AddControllerYawInput(LookAxisVector.X);
	}	
}

void ACkrunPlayerController::Jump() 
{
	if (PlayerCharacter)
	{
		PlayerCharacter->Jump();
	}	
}

void ACkrunPlayerController::Crouch()
{
	if (PlayerCharacter)
	{			
		if(PlayerCharacter->bIsCrouched)
		{
			PlayerCharacter->UnCrouch();
		}
		else
		{
			PlayerCharacter->Crouch();
		}		
	}	
}

void ACkrunPlayerController::ToggleInventory()
{
	const bool bIsInventoryCollapsed = InventoryMenuHUD->GetVisibility() == ESlateVisibility::Collapsed;

	const TSharedPtr<SWidget> InventoryMenuWidget = InventoryMenuHUD->TakeWidget();	
	
	if(bIsInventoryCollapsed)
	{
		SetIgnoreLookInput(true);
		SetShowMouseCursor(true);
		InventoryMenuHUD->SetVisibility(ESlateVisibility::SelfHitTestInvisible);	

		FInputModeGameAndUI InputModeGameAndUI;
		InputModeGameAndUI.SetWidgetToFocus(InventoryMenuWidget);
		InputModeGameAndUI.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		InputModeGameAndUI.SetHideCursorDuringCapture(true);
		SetInputMode(InputModeGameAndUI);	
	}
	else
	{
		ResetIgnoreLookInput();
		SetShowMouseCursor(false);
		InventoryMenuHUD->SetVisibility(ESlateVisibility::Collapsed);	

		const FInputModeGameOnly InputModeGameOnly;		
		SetInputMode(InputModeGameOnly);
	}
	
}
