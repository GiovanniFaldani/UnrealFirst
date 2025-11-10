// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Custom/CPP_PickUp.h"

// Sets default values
ACPP_PickUp::ACPP_PickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_PickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_PickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

