// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FocusGameMode.generated.h"

UENUM(BlueprintType)
enum class EHitPosition : uint8
{
	None			UMETA(DisplayName = "None"),
	High			UMETA(DisplayName = "High"),
	Mid				UMETA(DisplayName = "Mid"),
	Low				UMETA(DisplayName = "Low"),
};

UENUM(BlueprintType)
enum class EComboType : uint8
{
	NoCombo				UMETA(DisplayName = "NoCombo"),
	FH					UMETA(DisplayName = "FocusHeal"),
	HH					UMETA(DisplayName = "HeatHeal"),
	FD					UMETA(DisplayName = "FocusDamage"),
	FS					UMETA(DisplayName = "FocusStrike"),
	HD					UMETA(DisplayName = "HeatDamage"),
	HS					UMETA(DisplayName = "HeatStrike")
};

UENUM(BlueprintType)
enum class EFighter : uint8
{
	NoFighter			UMETA(DisplayName = "NoFighter"),
	Fighter0			UMETA(DisplayName = "Fighter0"),
	Fighter1			UMETA(DisplayName = "Fighter1"),
	Both				UMETA(DisplayName = "Both"),
};

USTRUCT(BlueprintType)
struct FCombo
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EComboType ComboType;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 Segment;
};

USTRUCT(BlueprintType)
struct FMove
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FName NomeMossa;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EHitPosition HitPosition;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 FocusToUnlock;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 FocusRecharge;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 HeatCost;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 LowDamage;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 HighDamage;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 BonusDamage;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FCombo> Combos;
};

USTRUCT(BlueprintType)
struct FPlayerLog
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EFighter Fighter;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 HeatChange;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 DamageInflicted;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 FocusChange;
	
};

USTRUCT(BlueprintType)
struct FSegmentLog
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FPlayerLog FasterPlayer;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FPlayerLog SlowerPlayer;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bSameSpeed;
};

USTRUCT(BlueprintType)
struct FTurnLog
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FSegmentLog> Turns;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EComboType Fighter0Combo;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EComboType Fighter1Combo;
	
};
/**
 * 
 */
UCLASS()
class PROJECTFOCUS_API AFocusGameMode : public AGameModeBase
{
	GENERATED_BODY()

	void ProcessTurn();
	
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FMove> Fighter0Moveset;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FMove> Fighter1Moveset;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<bool> ArePlayersReady;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EFighter PlayerToHeatReset;
	
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	//TArray<EFighter> PerfectParryLog;
};
