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

	FCollisionObjectQueryParams QueryParams;
	QueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
	QueryParams.AddObjectTypesToQuery(ECC_PhysicsBody);
	TArray<FOverlapResult> OutOverLapsSiphon;
	FCollisionShape CollShapeSiphon;
	CollShapeSiphon.SetSphere(SiphonComp->GetScaledSphereRadius());
	GetWorld()->OverlapMultiByObjectType(OutOverLapsSiphon, GetActorLocation(), FQuat::Identity, QueryParams, CollShapeSiphon);

	TArray<FOverlapResult> OutOverLapsSphere;
	FCollisionShape CollShapeSphere;
	CollShapeSphere.SetSphere(SphereComp->GetUnscaledSphereRadius());
	GetWorld()->OverlapMultiByObjectType(OutOverLapsSphere, GetActorLocation(), FQuat::Identity, QueryParams, CollShapeSphere);

	for (FOverlapResult Result : OutOverLapsSiphon) {
		UPrimitiveComponent* Overlap = Result.GetComponent();
		if (Overlap && Overlap->IsSimulatingPhysics()) {
			Overlap->AddRadialForce(GetActorLocation(), SiphonComp->GetScaledSphereRadius(),-2000.0f,ERadialImpulseFalloff::RIF_Constant,true);
		}
	}
	for (FOverlapResult Result : OutOverLapsSphere) {
		UPrimitiveComponent* Overlap = Result.GetComponent();
		if (Overlap && Overlap->IsSimulatingPhysics()) {
			Overlap->DestroyComponent();
			PlayEffects();
		}
	}

}

void AFPSBlacHole::PlayEffects()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, DestroyVFX, GetActorLocation());
}