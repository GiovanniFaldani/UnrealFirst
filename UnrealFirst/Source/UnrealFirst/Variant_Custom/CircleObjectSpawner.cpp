// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Custom/CircleObjectSpawner.h"
#include "Math/UnrealMathUtility.h"
#include "CPP_Basic_Actor.h"

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

	Spawn();
}


// Called every frame
void UCircleObjectSpawner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCircleObjectSpawner::Spawn() {

	// set spawn angles based on item number

	float AngleIncrease{ 360.0f / ItemNumber };

	for (int i = 0; i < ItemNumber; i++) {

		FVector Offset = FVector(1.0f, 0.0f, 0.0f).RotateAngleAxis(i * AngleIncrease, FVector(.0f, .0f, 1.0f));

		//UE_LOG(LogTemp, Warning, TEXT("Vector offset: %f, %f, %f\n"), Offset.X, Offset.Y, Offset.Z);

		FVector SpawnLocation{ Center + Radius * Offset};

		FVector SpawnScale{ FVector(1.0f, 1.0f, 1.0f) };

		FRotator SpawnRotation{ FRotator(.0f, .0f, .0f) };

		FTransform SpawnTransform{ };

		SpawnTransform.SetLocation(SpawnLocation);
		SpawnTransform.SetRotation(SpawnRotation.Quaternion());
		SpawnTransform.SetScale3D(SpawnScale);

		FActorSpawnParameters SpawnParams{ };

		SpawnParams.Owner = GetOwner();
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		GetWorld()->SpawnActor<AActor>( // Actor spawning function
			ToSpawn,
			SpawnTransform,
			SpawnParams
		);

	}
}

