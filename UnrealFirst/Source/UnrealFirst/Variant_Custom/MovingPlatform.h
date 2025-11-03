// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MovingPlatform.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALFIRST_API UMovingPlatform : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMovingPlatform();

	// TODO crea equivalente del blueprint della piattaforma mobile tra waypoint

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Moving_Platform")
	TArray<FVector> WayPoints{ };

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Moving_Platform")
	TArray<float> TravelTimes{ };

private:

	UPROPERTY(EditAnywhere, Category = "Moving_Platform")
	FVector StartPosition{ };

	UPROPERTY(EditAnywhere, Category = "Moving_Platform")
	int CurrentIndex{ 1 };

	UPROPERTY(EditAnywhere, Category = "Moving_Platform")
	float PercentageComplete{ 0. };

	UPROPERTY(EditAnywhere, Category = "Moving_Platform")
	float ElapsedTime{ 0. };


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void MoveBetweenWaypoints(float DeltaTime);
};
