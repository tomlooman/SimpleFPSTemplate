// Fill out your copyright notice in the Description page of Project Settings.


#include "ViewFinderSubsystem.h"

#include "SlicedProceduralActor.h"


void UViewFinderSubsystem::CaptureActorsInView(FVector CameraOrigin, FRotator CameraDirection, TArray<UPrimitiveComponent*> OverlappedMeshes)
{
	if (OverlappedMeshes.Num() == 0)
	{
		return;
	}
	
	// Reset
	CapturedMeshes.Empty();

	FTransform CameraTM;
	CameraTM.SetTranslation(CameraOrigin);
	CameraTM.SetRotation(CameraDirection.Quaternion());

	for (UPrimitiveComponent* PrimComp : OverlappedMeshes)
	{
		FCapturedStaticMesh NewMesh;
		//NewMesh.MeshComp = Cast<UStaticMeshComponent>(PrimComp);
		if (NewMesh.MeshComp == nullptr)
		{
			continue;
		}
		
		NewMesh.bSimulatePhysics = PrimComp->IsSimulatingPhysics();

		CapturedMeshes.Add(NewMesh);
	}
}


void UViewFinderSubsystem::SpawnActorsFromCapture(FVector CameraOrigin, FRotator CameraDirection)
{
	FTransform CameraTM;
	CameraTM.SetTranslation(CameraOrigin);
	CameraTM.SetRotation(CameraDirection.Quaternion());

	for (FCapturedStaticMesh CA : CapturedMeshes)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		
		//FVector SpawnLocation = CameraTM.TransformPosition(CA.LocalPosition);
		//FRotator SpawnRotation = CameraTM.TransformRotation(CA.LocalRotation).Rotator();
		
		//ASlicedProceduralActor* NewActor = Cast<ASlicedProceduralActor>(GetWorld()->SpawnActor<AActor>(ASlicedProceduralActor::StaticClass(), SpawnLocation, SpawnRotation, SpawnParams));
		
		//NewActor->SetActorLocationAndRotation(SpawnLocation, SpawnRotation);
		//NewActor->SetActorScale3D(CA.Scale);

	}
}