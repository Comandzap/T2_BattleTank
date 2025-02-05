// Fill out your copyright notice in the Description page of Project Settings.

#include "Battletank.h"
#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	//auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT(" %f"), Throttle);


	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

