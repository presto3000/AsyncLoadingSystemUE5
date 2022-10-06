// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AL_PartData.generated.h"

class UAL_SkeletalMeshComp;
class UAL_StaticMeshComp;
/**
 * 
 */
UENUM(BlueprintType)
enum class ESkeletalPart : uint8
{
	None,
	SkeletalPart_1,
	SkeletalPart_2,
	SkeletalPart_3,
};

UENUM(BlueprintType)
enum class EStaticPart : uint8
{
	None,
	StaticPart_1,
	StaticPart_2,
	StaticPart_3,
};


UCLASS()
class ASYNCLOADINGSYSTEM_API UAL_PartData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, Category = Parts)
	TMap<ESkeletalPart, TSoftClassPtr<UAL_SkeletalMeshComp>> AvailableSkeletalParts;
	
	UPROPERTY(EditAnywhere, Category = Parts)
	TMap<EStaticPart, TSoftClassPtr<UAL_StaticMeshComp>> AvailableStaticParts;

protected:

	UPROPERTY(EditAnywhere, Category = Async_Helper_Data)
	TArray<ESkeletalPart> SkeletalPartsToFind;

	UPROPERTY(EditAnywhere, Category = Async_Helper_Data)
	TArray<EStaticPart> StaticPartsToFind;

#pragma region FUNCTIONS

	UFUNCTION(BlueprintCallable, Category = "Data Async Load Helper")
	void RequestAsyncLoad_SkeletalPart(const UObject* DataOwner);

	UFUNCTION(BlueprintCallable, Category = "Data Async Load Helper")
	void RequestAsyncLoad_StaticPart(const UObject* DataOwner);

	UFUNCTION(BlueprintCallable, Category = "Data Async UnLoad Helper")
	void UnloadAllObjects(const UObject* DataOwner);

	UFUNCTION(BlueprintPure, Category = "Data Async Getters")
	TArray<UAL_SkeletalMeshComp*> GetAvailableSkeletalParts() const;

	UFUNCTION(BlueprintPure, Category = "Data Async Getters")
	TArray<UAL_StaticMeshComp*> GetAvailableStaticParts() const;

#pragma endregion FUNCTIONS

	UFUNCTION()
	void OnSkeletalPartsLoaded();

	UFUNCTION()
	void OnStaticPartsLoaded();
	
private:

	TArray<UAL_SkeletalMeshComp*> FoundSkeletalParts;
	TArray<UAL_StaticMeshComp*> FoundStaticParts;
	TArray<FSoftObjectPath> ObjectsToUnload;
	
};
