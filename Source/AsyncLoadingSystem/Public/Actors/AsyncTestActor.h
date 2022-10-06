// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/PartInterface.h"
#include "AsyncTestActor.generated.h"

class UAL_SkeletalMeshComp;
class UAL_StaticMeshComp;
UCLASS()
class ASYNCLOADINGSYSTEM_API AAsyncTestActor : public AActor, public IPartInterface
{
	GENERATED_BODY()

public:
	AAsyncTestActor();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Meshes)
	UAL_StaticMeshComp* AsyncStaticMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Meshes)
	UAL_SkeletalMeshComp* AsyncSkeletalMesh;
	
	virtual void BeginPlay() override;
	
};
