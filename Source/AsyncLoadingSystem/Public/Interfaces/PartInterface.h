// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PartInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UPartInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ASYNCLOADINGSYSTEM_API IPartInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnRandomLoad_Static();
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnRandomLoad_Skeletal();
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnTryAsyncLoad_Static();
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnTryAsyncLoad_Skeletal();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnUnload();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnLoopRandomLoad_Static();
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnLoopRandomLoad_Skeletal();
};
