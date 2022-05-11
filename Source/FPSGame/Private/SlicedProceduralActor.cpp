// Fill out your copyright notice in the Description page of Project Settings.


#include "SlicedProceduralActor.h"

#include "DynamicMeshComponent.h"


ASlicedProceduralActor::ASlicedProceduralActor()
{
	DynamicMeshComp = CreateDefaultSubobject<UDynamicMeshComponent>("DynamicMeshComp");
	RootComponent = DynamicMeshComp;
}
