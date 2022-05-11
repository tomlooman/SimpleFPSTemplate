// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SlicedProceduralActor.generated.h"

class UDynamicMeshComponent;

UCLASS()
class FPSGAME_API ASlicedProceduralActor : public AActor
{
	GENERATED_BODY()

	UPROPERTY()
	UDynamicMeshComponent* DynamicMeshComp;
                             
	ASlicedProceduralActor();
};
