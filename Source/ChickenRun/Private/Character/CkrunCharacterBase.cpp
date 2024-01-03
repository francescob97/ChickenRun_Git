// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CkrunCharacterBase.h"

ACkrunCharacterBase::ACkrunCharacterBase()
{ 	
	PrimaryActorTick.bCanEverTick = false;

	HoldItem = CreateDefaultSubobject<USkeletalMeshComponent>("Hold Item");
	HoldItem->SetupAttachment(GetMesh(), FName("ItemHandSocket"));
	HoldItem->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

void ACkrunCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}
