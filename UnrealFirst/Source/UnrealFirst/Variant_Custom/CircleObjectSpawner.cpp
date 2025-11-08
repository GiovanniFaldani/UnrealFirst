// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Custom/CircleObjectSpawner.h"

// Sets default values for this component's properties
UCircleObjectSpawner::UCircleObjectSpawner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCircleObjectSpawner::BeginPlay()
{
	Super::BeginPlay();

	// set center
	Center = GetOwner()->GetActorLocation();	
}


// Called every frame
void UCircleObjectSpawner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCircleObjectSpawner::Spawn(AActor* ToSpawn) {

	// TODO set spawn angles based on item number

	for (int i = 0; i < ItemNumber; i++) {
		//GetWorld()->SpawnActor( // Actor spawning function

		//);

	}
}

