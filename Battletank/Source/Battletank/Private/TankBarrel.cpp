// Fill out your copyright notice in the Description page of Project Settings.

#include "Battletank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativSpeed)
{

	//auto Time = GetWorld()->GetTime
	//UE_LOG(LogTemp, Warning, TEXT(" aiming at "));
	auto ElevationChange = FMath::Clamp(RelativSpeed,-1.f,1.f) * MaxDegreesPerSecound * GetWorld()->DeltaTimeSeconds;
	auto Elevation = FMath::Clamp((RelativeRotation.Pitch + ElevationChange),MinElevationDegree,MaxElevationDegree);

	SetRelativeRotation(FRotator(Elevation, 0, 0));
}

