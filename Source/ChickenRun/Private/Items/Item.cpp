// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"

#include "Components/SphereComponent.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(RootComponent);
	
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	ItemMesh->SetGenerateOverlapEvents(false);
	ItemMesh->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	ItemMesh->SetCollisionObjectType(ECC_WorldDynamic);
	ItemMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	ItemMesh->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	ItemMesh->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	ItemMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
	ItemMesh->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Block);	
	ItemMesh->SetupAttachment(RootComponent);

	SphereTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("SphereTrigger"));
	SphereTrigger->SetupAttachment(RootComponent);
	SphereTrigger->SetGenerateOverlapEvents(false);
	SphereTrigger->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereTrigger->SetCollisionObjectType(ECC_WorldDynamic);
	SphereTrigger->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	SphereTrigger->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::Grab()
{
}



