// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurrent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();


	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurrentReference(UTankTurrent* TurretToSet);

	void moveBarrelToward(FVector AimDirection);


	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurrent* Turrent = nullptr;
		
	
};
