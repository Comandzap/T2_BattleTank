// Fill out your copyright notice in the Description page of Project Settings.

#include "Battletank.h"
#include "TankTurrent.h"




void UTankTurrent::Rotate(float RelativSpeed)
{

	auto RotateChange = FMath::Clamp(RelativSpeed, -1.f, 1.f) * MaxDegreesPerSecound * GetWorld()->DeltaTimeSeconds;
	auto Rotate = RelativeRotation.Yaw + RotateChange;

	SetRelativeRotation(FRotator(0, Rotate, 0));
}