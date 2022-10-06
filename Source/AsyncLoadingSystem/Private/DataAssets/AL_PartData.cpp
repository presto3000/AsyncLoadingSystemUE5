// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/AL_PartData.h"

#include "Core/Singleton/AL_GameInstance.h"

void UAL_PartData::RequestAsyncLoad_SkeletalPart(const UObject* DataOwner)
{
	// Check if available parts && Key arrays have more than 0 indexes
	if (AvailableSkeletalParts.Num() > 0 && SkeletalPartsToFind.Num() > 0)
	{
		
	}
	// Create asset path list

	// iterate over all incoming key names and then find the value of that key in our TMAP


		// Add that found object to both PathList & our objects arrays
	// once the array is filled get our asset loader to load our array
}

void UAL_PartData::RequestAsyncLoad_StaticPart(const UObject* DataOwner)
{
}

void UAL_PartData::UnloadAllObjects(const UObject* DataOwner)
{
	// Get our game instance
	UAL_GameInstance* MyGameInstance = Cast<UAL_GameInstance>(DataOwner->GetWorld()->GetGameInstance());
	// if game instance is valid
	if (!MyGameInstance) return;
	
	if (ObjectsToUnload.Num() <= 0) return;

	FoundStaticParts.Empty();
	FoundSkeletalParts.Empty();
	
	// iterate over our ObjectsToUnload Array
	for (int Index = 0; Index < ObjectsToUnload.Num(); Index++)
	{
		// create a const temp var to hold the name of the object @ array index
		const FSoftObjectPath& PathName = ObjectsToUnload[Index];
		MyGameInstance->AssetLoader.Unload(PathName);
	}
}

TArray<UAL_SkeletalMeshComp*> UAL_PartData::GetAvailableSkeletalParts() const
{
	return FoundSkeletalParts;
}

TArray<UAL_StaticMeshComp*> UAL_PartData::GetAvailableStaticParts() const
{
	return FoundStaticParts;
}
