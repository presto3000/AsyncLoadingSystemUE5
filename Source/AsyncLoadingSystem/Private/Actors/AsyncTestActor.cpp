// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/AsyncTestActor.h"

#include "Parts/Skeletal/AL_SkeletalMeshComp.h"
#include "Parts/Static/AL_StaticMeshComp.h"


// Sets default values
AAsyncTestActor::AAsyncTestActor()
{
	AsyncSkeletalMesh = CreateDefaultSubobject<UAL_SkeletalMeshComp>(TEXT("Skeletal Mesh Comp"));
	AsyncSkeletalMesh->SetupAttachment(RootComponent);
	
	AsyncStaticMesh = CreateDefaultSubobject<UAL_StaticMeshComp>(TEXT("Static Mesh Comp"));
	AsyncStaticMesh->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void AAsyncTestActor::BeginPlay()
{
	Super::BeginPlay();
	
}


