// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/PartInterface.h"
#include "AsyncTestActor.generated.h"

UCLASS()
class ASYNCLOADINGSYSTEM_API AAsyncTestActor : public AActor, public IPartInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAsyncTestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
