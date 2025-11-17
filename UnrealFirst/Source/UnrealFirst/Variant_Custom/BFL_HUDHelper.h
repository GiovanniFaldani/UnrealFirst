// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CommonActivatableWidget.h"
#include "BFL_HUDHelper.generated.h"

class UCommonActivatableWidget; // Forward declaration di una classe per evitare di compilare l'intero file, posso evitare di fare l'include qui e metterlo nel cpp

/**
 * 
 */
UCLASS()
class UNREALFIRST_API UBFL_HUDHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "HUD Helper", meta = (WorldContext="WorldContext"))
	static void PushWidget(const UObject* WorldContext, TSubclassOf<UCommonActivatableWidget> WidgetToPush);
	
};
