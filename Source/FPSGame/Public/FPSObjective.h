// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSObjective.generated.h"

UCLASS()
class FPSGAME_API AFPSObjective : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSObjective();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditDefaultsOnly, Category = "Objective")
	UParticleSystem* ParticleTemplate;

	UFUNCTION(BlueprintCallable, Category = "Objective")
	void SpawnEffect();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
