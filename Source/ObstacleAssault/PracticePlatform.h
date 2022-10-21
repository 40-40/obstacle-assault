// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PracticePlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API APracticePlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APracticePlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere)
    FVector PlatformVelocity = FVector(100, 0, 0);

    UPROPERTY(EditAnywhere)
    FVector StartingPosition;

    UPROPERTY(EditAnywhere)
    float MoveDistance = 100;
};
