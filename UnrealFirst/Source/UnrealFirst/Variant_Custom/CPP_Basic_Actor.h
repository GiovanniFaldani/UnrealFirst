#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "CPP_Basic_Actor.generated.h"

UCLASS()
class UNREALFIRST_API ABasicActor : public AActor
{
	GENERATED_BODY()

public:
	ABasicActor();

private:
	UPROPERTY(EditAnywhere)
	UStaticMesh* StaticMesh;

	USphereComponent* dynamicallyCreatedSphere = nullptr;
	UStaticMeshComponent* dynamicMesh = nullptr;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	void SpawnSphere();

};