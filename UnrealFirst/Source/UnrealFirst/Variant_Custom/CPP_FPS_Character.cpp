// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Custom/CPP_FPS_Character.h"
#include "CPP_FPS_InteractionComponent.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
// Costruttore per settre valori iniziali e struttora attore
ACPP_FPS_Character::ACPP_FPS_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creaiamo la mesh da aggiungere nella gerarchia dei componenti visibili
	CompanionMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Companion"));

	// ... Altri settaggi relativi al componente

	CompanionMesh->SetupAttachment(RootComponent);

	// Creiamo il nostro componente di logica, uguale a quello visibile ma senza il setup

	InteractionComponent = CreateDefaultSubobject<UCPP_FPS_InteractionComponent>(TEXT("Interaction"));
	InteractionComponent->RadiusInteraction = 200.f;
	InteractionComponent->DistanceInteraction = 1000.f;

	/*InteractionComponent->Transform.Add(FTransform());
	InteractionComponent->Transform.Add(FTransform());
	InteractionComponent->Transform.Add(FTransform());*/

}

// Called when the game starts or when spawned
void ACPP_FPS_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_FPS_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

// Called to bind functionality to input
void ACPP_FPS_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACPP_FPS_Character::OnContruction()
{

}




