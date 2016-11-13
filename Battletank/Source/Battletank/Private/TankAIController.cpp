// Fill out your copyright notice in the Description page of Project Settings.

#include "Battletank.h"
#include "TankAIController.h"




void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


	auto ControllTank = GetControlledTank();
	if (!ControllTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController did not find PlayerTank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found %s"), *GetPlayerTank()->GetName());
	}

}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
	
	
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr; }
	return Cast<ATank>(PlayerTank);

}




