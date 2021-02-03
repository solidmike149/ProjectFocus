// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GICpp.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFOCUS_API UGICpp : public UGameInstance
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
	FString MyFighterName;

	UPROPERTY(BlueprintReadWrite)
	FString TheirFighterName;
};
