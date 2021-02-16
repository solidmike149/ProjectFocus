// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include <Engine/DataTable.h>
#include "FighterInfoDataAsset.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FFighter
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FName FighterID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UDataTable* Moveset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int StartingFocus;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int StartingHeat;
};


UCLASS(BlueprintType)
class PROJECTFOCUS_API UFighterInfoDataAsset : public UDataAsset
{
	GENERATED_BODY()
	

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (TitleProperty = "FighterID"))
	TArray<FFighter> Fighters;
};
