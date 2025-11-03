// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Custom/InteractionComponent.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UInteractionComponent::UInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!GetWorld())
	{
		return;
	}

	ActorsFound = InteractionTraceObjects(DistanceInteraction, RadiusInteraction);

	float Distance{};
	float InitDistance = FLT_MAX;
	ClosestActor = nullptr;

	for (AActor* Actor : ActorsFound)
	{
		Distance = Actor->GetDistanceTo(GetOwner());

		if (Distance < InitDistance) {
			InitDistance = Distance;
			ClosestActor = Actor;
		}

	}

	if (bDebugInteraction && IsValid(ClosestActor))
	{
		DrawDebugSphere(
			GetWorld(),
			ClosestActor->GetActorLocation(),
			200.f,
			12,
			FColor::Emerald,
			false,
			-1.f,
			(uint8)0U,
			10
		);
	}

}

TArray<AActor*> UInteractionComponent::InteractionTraceObjects(const float Distance, const float Radius)
{
	FVector EndTrace{ GetOwner()->GetActorLocation() + GetOwner()->GetActorForwardVector() * DistanceInteraction };

	TArray<AActor*> ActorsToIgnore;
	TArray<FHitResult> Hits;

	TArray<AActor*> ActorsFoundInternal;

	if (!IsValid(GetWorld()))
	{
		return ActorsFoundInternal;
	}

	UKismetSystemLibrary::SphereTraceMultiForObjects(
		GetWorld(), // Context to pass, we always pass world context here
		GetOwner()->GetActorLocation(), // Start trace
		EndTrace, // End trace
		RadiusInteraction, // Radius trace
		ObjectTypesToInteract, // ObjectTypes
		false, // complex trace
		ActorsToIgnore,	// 
		bDebugInteraction ? EDrawDebugTrace::ForOneFrame : EDrawDebugTrace::None,
		Hits, // HitResults to save hit information
		true // Ignore self
	);

	for (FHitResult HitResult : Hits)
	{
		if (IsValid(HitResult.GetActor()))
		{
			ActorsFoundInternal.AddUnique(HitResult.GetActor());
		}
	}

	return ActorsFoundInternal;
}

