// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), BlueprintType, Blueprintable, abstract ) // Tag per esporre la classe all'editor blueprint
class UNREALFIRST_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractionComponent();

	//** Trace Interaction Distance
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "FPS_Character")
	float DistanceInteraction{ 1500.f };

	//** Trace Interaction Radius
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "FPS_Character")
	float RadiusInteraction{ 400.f };

	//** Objects types
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "FPS_Character")
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypesToInteract;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "FPS_Character")
	bool bDebugInteraction{ false };

	//** Character Name
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "FPS_Character")
	FString CharacterName{ "" };

private:
	UPROPERTY(EditAnywhere, Category = "FPS_Character")
	TArray<AActor*> ActorsFound{ };

	UPROPERTY(EditAnywhere, Category = "FPS_Character")
	AActor* ClosestActor{ };

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Interaction Trace Objects
	UFUNCTION(BluePrintCallable, Category = "FPS_Character")
	TArray<AActor*> InteractionTraceObjects(const float Distance, const float Radius);
};
