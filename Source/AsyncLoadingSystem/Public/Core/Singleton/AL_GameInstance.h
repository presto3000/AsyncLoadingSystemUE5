// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StreamableManager.h"
#include "AL_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ASYNCLOADINGSYSTEM_API UAL_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	FStreamableManager AssetLoader;
};
