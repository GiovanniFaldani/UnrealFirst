// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Custom/MovingPlatform.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UMovingPlatform::UMovingPlatform()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartPosition = WayPoints[0];

	// Check for array length parity
	if (WayPoints.Num() != TravelTimes.Num()) 
	{
		UE_LOG(LogTemp, Fatal, TEXT("Waypoints and Travel times must have the same length!"));
	}
	
}


// Called every frame
void UMovingPlatform::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	MoveBetweenWaypoints(DeltaTime);
}

void UMovingPlatform::MoveBetweenWaypoints(float DeltaTime)
{
	// Update time-sensitive data
	ElapsedTime += DeltaTime;
	PercentageComplete = FMath::Clamp(ElapsedTime / TravelTimes[CurrentIndex], 0., 1.);


	// Platform moving logic
	FVector newPos = UKismetMathLibrary::VLerp(StartPosition, WayPoints[CurrentIndex], PercentageComplete);
	GetOwner()->SetActorLocation(newPos);

	if (PercentageComplete >= 1.f)
	{
		StartPosition = WayPoints[CurrentIndex];
		CurrentIndex++;
		PercentageComplete = 0.f;
		ElapsedTime = 0.f;

		if (!WayPoints.IsValidIndex(CurrentIndex))
		{
			CurrentIndex = 0;
		}
	}
}

