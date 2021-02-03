// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FighterPlayerController.generated.h"

UENUM(BlueprintType)
enum class EHitPosition : uint8
{
	High,

	Mid,

	Low,
};

USTRUCT(BlueprintType)
struct FMove
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FName NomeMossa;

	UPROPERTY(EditAnywhere)
	EHitPosition HitPosition;

	UPROPERTY(EditAnywhere)
	int FocusToUnlock;

	UPROPERTY(EditAnywhere)
	int FocusRecharge;

	UPROPERTY(EditAnywhere)
	int HeatCost;

	UPROPERTY(EditAnywhere)
	int LowDamage;

	UPROPERTY(EditAnywhere)
	int HighDamage;

	UPROPERTY(EditAnywhere)
	int BonusDamage;

	UPROPERTY(EditAnywhere)
	TMap<EHitPosition, int> Combo;
};

/**
 * 
 */
UCLASS()
class PROJECTFOCUS_API AFighterPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	AFighterPlayerController();

	virtual void BeginPlay() override;

	UFUNCTION()
	UDataTable* GetDataTableFromGameInstance();
	
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	class UDataTable* MovesInfo;

	UPROPERTY()
	class UGICpp* GameInstance;
};
