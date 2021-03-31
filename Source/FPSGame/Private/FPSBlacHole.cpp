// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSBlacHole.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
AFPSBlacHole::AFPSBlacHole()
{
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	SphereComp->SetupAttachment(MeshComp);

	SiphonComp = CreateDefaultSubobject<USphereComponent>(TEXT("SiphonComp"));
	SiphonComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	SiphonComp->SetupAttachment(MeshComp);



}

// Called when the game starts or when spawned
void AFPSBlacHole::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSBlacHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TArray<UPrimitiveComponent*> OverlappingArray;
	GetOverlappingComponents(OverlappingArray);
	for (auto& Comp : OverlappingArray) {

		if ( (Comp != NULL) && Comp->IsSimulatingPhysics())
		{
			Comp->AddImpulseAtLocation(GetVelocity() * -100.0f, GetActorLocation());
		}
	}
}
