// Fill out your copyright notice in the Description page of Project Settings.

#include "Variant_Custom/BFL_HUDHelper.h"
#include "CPP_PlayerController.h"
#include "CanvasStackBase.h"
#include <Kismet/GameplayStatics.h>

void UBFL_HUDHelper::PushWidget(const UObject* WorldContext, TSubclassOf<UCommonActivatableWidget> WidgetToPush ) // Try passing PlayerController here?
{
	UE_LOG(LogTemp, Warning, TEXT("Pushing Widget"));

	if(!IsValid(GWorld)) UE_LOG(LogTemp, Display, TEXT("GWorld not found"));

	//UWorld* World = GEngine->GameViewport->GetWorld();

	// Get Player controller
	ACPP_PlayerController* PlayerController = Cast<ACPP_PlayerController>(UGameplayStatics::GetPlayerController(WorldContext, 0));
		//Cast<ACPP_PlayerController>(World->GetFirstPlayerController());
		//Cast<ACPP_PlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	if (!IsValid(PlayerController))
	{
		UE_LOG(LogTemp, Display, TEXT("Controller not found"));
		return;
	}

	// Access Canvas Stack Base
	TObjectPtr<UCanvasStackBase> CanvasStack = PlayerController->GetCanvasStack();

	if (!IsValid(CanvasStack)) UE_LOG(LogTemp, Display, TEXT("Canvas Stack not found"));

	// Push Widget
	CanvasStack->PushWidgetToHudStack(WidgetToPush);
}
