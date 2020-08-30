// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "HeadMountedDisplay.h"
#include "MotionControllerComponent.h"
#include "XRMotionControllerBase.h"
#include "Components/SceneComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Camera/CameraComponent.h"


#include "VRPawn.generated.h"

UCLASS()
class TODS_API AVRPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AVRPawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY() //Root scene
	USceneComponent* m_scene;
	UPROPERTY() //Movement controller
	UFloatingPawnMovement* m_movementController;
	UPROPERTY() //Root camera
	USceneComponent* m_cameraRoot;
	UPROPERTY() //Actual camera
	UCameraComponent* m_camera;

	UPROPERTY()
	UMotionControllerComponent* m_leftController;
	UPROPERTY()
	UMotionControllerComponent* m_rightController;
};

