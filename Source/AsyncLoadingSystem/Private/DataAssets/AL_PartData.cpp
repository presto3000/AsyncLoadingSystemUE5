// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/AL_PartData.h"

#include "Core/Singleton/AL_GameInstance.h"
#include "Parts/Skeletal/AL_SkeletalMeshComp.h"
#include "Parts/Static/AL_StaticMeshComp.h"

void UAL_PartData::RequestAsyncLoad_SkeletalPart(const UObject* DataOwner)
{
	// Check if available parts && Key arrays have more than 0 indexes
	if (AvailableSkeletalParts.Num() > 0 && SkeletalPartsToFind.Num() > 0)
	{
		// Create asset path list
		TArray<FSoftObjectPath> AssetsToLoad;
		// iterate over all incoming key names and then find the value of that key in our TMAP
		for (int Index = 0; Index < SkeletalPartsToFind.Num(); Index++)
		{
			const ESkeletalPart PartName = SkeletalPartsToFind[Index];
			// Add that found object to both PathList & our objects arrays

			AssetsToLoad.AddUnique(AvailableSkeletalParts.Find(PartName)->ToSoftObjectPath());
			ObjectsToUnload.AddUnique(AvailableSkeletalParts.Find(PartName)->ToSoftObjectPath());
		}


		
		// once the array is filled get our asset loader to load our array
		UAL_GameInstance* MyGameInstance = Cast<UAL_GameInstance>(DataOwner->GetWorld()->GetGameInstance());
		if (!MyGameInstance) return;

		MyGameInstance->AssetLoader.RequestAsyncLoad(AssetsToLoad, FStreamableDelegate::CreateUObject(this, &UAL_PartData::OnSkeletalPartsLoaded));
	}

}

void UAL_PartData::RequestAsyncLoad_StaticPart(const UObject* DataOwner)
{
	// Check if available parts && Key arrays have more than 0 indexes
	if (AvailableStaticParts.Num() > 0 && StaticPartsToFind.Num() > 0)
	{
		// Create asset path list
		TArray<FSoftObjectPath> AssetsToLoad;
		// iterate over all incoming key names and then find the value of that key in our TMAP
		for (int Index = 0; Index < StaticPartsToFind.Num(); Index++)
		{
			const EStaticPart PartName = StaticPartsToFind[Index];
			// Add that found object to both PathList & our objects arrays

			AssetsToLoad.AddUnique(AvailableStaticParts.Find(PartName)->ToSoftObjectPath());
			ObjectsToUnload.AddUnique(AvailableStaticParts.Find(PartName)->ToSoftObjectPath());
		}
		
		// once the array is filled get our asset loader to load our array
		UAL_GameInstance* MyGameInstance = Cast<UAL_GameInstance>(DataOwner->GetWorld()->GetGameInstance());
		if (!MyGameInstance) return;

		MyGameInstance->AssetLoader.RequestAsyncLoad(AssetsToLoad, FStreamableDelegate::CreateUObject(this, &UAL_PartData::OnStaticPartsLoaded));
	}
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

void UAL_PartData::OnSkeletalPartsLoaded()
{
	// iterate over available skeletal parts and find the objects of the key name then add that object to our found part array
	for (int Index = 0; Index < SkeletalPartsToFind.Num(); Index++)
	{
		const ESkeletalPart PartName = SkeletalPartsToFind[Index];
		FoundSkeletalParts.AddUnique(AvailableSkeletalParts.Find(PartName)->Get()->GetDefaultObject<UAL_SkeletalMeshComp>());
	}
}

void UAL_PartData::OnStaticPartsLoaded()
{
	// iterate over available skeletal parts and find the objects of the key name then add that object to our found part array
	for (int Index = 0; Index < StaticPartsToFind.Num(); Index++)
	{
		const EStaticPart PartName = StaticPartsToFind[Index];
		FoundStaticParts.AddUnique(AvailableStaticParts.Find(PartName)->Get()->GetDefaultObject<UAL_StaticMeshComp>());
	}
}
