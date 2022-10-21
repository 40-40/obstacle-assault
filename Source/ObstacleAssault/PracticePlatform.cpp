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

    // Now we must check if the platforms distance moved is too far so we can send it back
    // How do we check distance moved? at first I thought of doing what I did in JS by setting up a default variable at 0 and code a counter to track each change but
    // As I continued to watch the course they introduced a method of FVector called "Dist" which returns the distance between two vectors as a float
    // :: is used to get the method from the FVector CLASS itself rather than using a method from a FVector we have declared
    float DistanceMoved = FVector::Dist(CurrentLocation, StartingPosition);

    // Now that we have a variable to check the distance moved every game tick we need to compare it with
    // the maximum distance we specified in the header file so we know if we have gone too far
    if(DistanceMoved > MoveDistance) {
        // if the distance between our current location and our starting position is greater than 100
        // we will make our platform move the opposite way in the X axis
        // remember it is a vector so changing it to negative will make it move backwards
        // now this has a bug where if the platform overshoots it will re position the location and drift so we will fix it
        FVector MoveDirection = PlatformVelocity.GetSafeNormal();
        // GetSafeNormal = It returns a normalised vector. It’s a vector going in the same direction but with a magnitude of 1 i.e. it only has direction.
        StartingPosition = StartingPosition + MoveDirection * MoveDistance;
        // MoveDirection * MoveDistance (1 in the X axis direction * 100)
        // Platforms starting position is updated to be in the current direction PlatformVelocity is setup to and a fixed distance that we declared in the header file
        SetActorLocation(StartingPosition);
        // Set the new location
        PlatformVelocity = -PlatformVelocity;
        // Reverse the movement

        // Recap
        // check if distance between the platforms current location and starting position is greater than specified move distance
        // setup a new vector to check what platformvelocity's current move direction is using .GetSafeNormal() (this will be either positive in the X axis or negative)
        // GetSafeNormal returns the vector with a value of 1 so we multiply it by our set distance to tell it how far it will go
        // So it will move either positive 100 on the X axis or negative 100 on the X axis since that is what we have setup
        // Remember to set actor location after changing values
        // Finally reverse the velocity direction for the next tick
    }
}

