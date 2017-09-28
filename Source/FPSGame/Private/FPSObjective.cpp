// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSObjective.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AFPSObjective::AFPSObjective()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshCompCPP"));
}

// Called when the game starts or when spawned
void AFPSObjective::BeginPlay()
{
	Super::BeginPlay();

	SpawnEffect();
}


void AFPSObjective::SpawnEffect()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleTemplate, GetActorLocation());
}


// Called every frame
void AFPSObjective::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//SpawnEffect();
}

