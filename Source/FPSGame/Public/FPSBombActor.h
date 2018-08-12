// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSBombActor.generated.h"

class UStaticMeshComponent;
class UParticleSystem;


UCLASS()
class FPSGAME_API AFPSBombActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSBombActor();

protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UMaterialInstanceDynamic* MaterialInst;

	FLinearColor CurrentColor;

	FLinearColor TargetColor;

	UPROPERTY(EditDefaultsOnly, Category = "BombActor")
	float ExplodeDelay;

	UPROPERTY(EditDefaultsOnly, Category = "BombActor")
	UParticleSystem* ExplosionTemplate;

	UFUNCTION()
	void Explode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
