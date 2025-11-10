#include "CPP_Basic_Actor.h"

ABasicActor::ABasicActor():AActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABasicActor::BeginPlay()
{
	Super::BeginPlay();

	// Create sphere mesh component to display the actor
    SpawnSphere();

}

void ABasicActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABasicActor::SpawnSphere()
{
    if (dynamicallyCreatedSphere == nullptr) {
        // you should specify outer as current actor (because this component is part of it)
        USphereComponent* DynamicallyCreatedSphere = NewObject<USphereComponent>(this, USphereComponent::StaticClass());
        DynamicallyCreatedSphere->RegisterComponent();
        // when component is dynamically created, you can use AttachToComponent, not SetupAttachment
        DynamicallyCreatedSphere->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
        DynamicallyCreatedSphere->InitSphereRadius(30.0f);
        //DynamicallyCreatedSphere->SetRelativeLocation(FVector(.0f, .0f, .0f));
        DynamicallyCreatedSphere->SetVisibility(true);
    }
}