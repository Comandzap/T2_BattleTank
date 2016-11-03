// Fill out your copyright notice in the Description page of Project Settings.

#pragma once




#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
		private:
	ATank* GetControlledTank() const;
	

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	


	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLockVectorHitLocation(FVector LookDirection,FVector& HitLocation) const;


	UPROPERTY (EditAnywhere)
	float CrossAirXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossAirYLocation = 0.3333;
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;
};
