// Fill out your copyright notice in the Description page of Project Settings.

#include "Battletank.h"
#include "TankBarrel.h"
#include "TankTurrent.h"
#include "TankAimingComponent.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts



void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	if (UGameplayStatics::SuggestProjectileVelocity(this,OutLaunchVelocity,StartLocation,HitLocation,LaunchSpeed,false,0,0,ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();

		moveBarrelToward(AimDirection);
		//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *TankName, *AimDirection.ToString());
	}//TODO kull måte å planlegge ting
	
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurrentReference(UTankTurrent* TurretToSet)
{
	if (!TurretToSet) { return; }
	Turrent = TurretToSet;
}
void UTankAimingComponent::moveBarrelToward(FVector AimDirection)
{
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotation;
	
	Turrent->Rotate(DeltaRotator.Yaw);
	Barrel->Elevate(DeltaRotator.Pitch);
}


