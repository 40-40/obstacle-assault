// Fill out your copyright notice in the Description page of Project Settings.


#include "PracticePlatform.h"

// Sets default values
APracticePlatform::APracticePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APracticePlatform::BeginPlay()
{
	Super::BeginPlay();
    // Get starting position value
	StartingPosition = GetActorLocation();
}

// Called every frame
void APracticePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    // Updates current location every tick
    FVector CurrentLocation = GetActorLocation();

    // Getting current ticks location and updating it with our set velocity in the header and * by deltatime
    CurrentLocation = CurrentLocation + PlatformVelocity * DeltaTime;

    // Update the platforms location to the location we update one line above
    // The value will still be updated in the game but your platform will not move unless you tell the game to update it!
    SetActorLocation(CurrentLocation);
}

