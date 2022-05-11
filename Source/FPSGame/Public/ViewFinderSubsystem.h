// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UDynamicMesh.h"
#include "Subsystems/WorldSubsystem.h"
#include "ViewFinderSubsystem.generated.h"


/* A single Actor 'captured' by the Camera/Photo to be used as template for spawning the copy elsewhere */
USTRUCT()
struct FCapturedStaticMesh
{
	GENERATED_BODY()

	UPROPERTY()
	UDynamicMesh* MeshComp;

	FTransform Transform;

	//FVector LocalPosition;

	//FQuat LocalRotation;

	//FVector Scale;

	bool bSimulatePhysics;
};


/**
 * 
 */
UCLASS()
class FPSGAME_API UViewFinderSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()


	/* Ideally store per-photo, for now just a single captured photo at once */
	UPROPERTY()
	TArray<FCapturedStaticMesh> CapturedMeshes;
	
	UFUNCTION(BlueprintCallable)
	void CaptureActorsInView(FVector CameraOrigin, FRotator CameraDirection, TArray<UPrimitiveComponent*> OverlappedMeshes);

	UFUNCTION(BlueprintCallable)
	void SpawnActorsFromCapture(FVector CameraOrigin, FRotator CameraDirection);
};
