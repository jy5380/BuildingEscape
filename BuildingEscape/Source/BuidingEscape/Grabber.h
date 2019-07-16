// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <PhysicsEngine/PhysicsHandleComponent.h>
#include <Components/InputComponent.h>
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUIDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
	
private:
	// How far reach in cm
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComp = nullptr;

	// Ray-cast and grab what in reach
	void Grab();

	void Release();

	void FindPhysicsHandleComponent();

	void SetupInputComponent();

	// Return hit for first physics body to reach
	const FHitResult GetFirstPhysicsBodyInReach();

	FVector GetReachLineStart();
	FVector GetReachLineEnd();
};