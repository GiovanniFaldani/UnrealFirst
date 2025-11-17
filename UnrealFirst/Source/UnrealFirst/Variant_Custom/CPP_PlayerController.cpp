// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Custom/CPP_PlayerController.h"

TObjectPtr<UCanvasStackBase> ACPP_PlayerController::GetCanvasStack()
{
	if (IsValid(CanvasStack))
		return CanvasStack;
	else
		return nullptr;
}
