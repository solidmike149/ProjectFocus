// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterPlayerController.h"
#include "Engine/DataTable.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "GICpp.h"

AFighterPlayerController::AFighterPlayerController()
{

}

void AFighterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//GetDataTableFromGameInstance();

}

UDataTable* AFighterPlayerController::GetDataTableFromGameInstance()
{
	if (Cast<UGICpp>(GetGameInstance()))
	{
		GameInstance = Cast<UGICpp>(GetGameInstance());
		GameInstance->MyFighterName;

		FString InitialFilePath = (TEXT("'/Game/ThirdPersonCPP/Data/"));

		FString CharacterFilePath = InitialFilePath.Append((TEXT("%s"), *GameInstance->MyFighterName));

		FString FinalFilePath = CharacterFilePath.Append(".");

		FString FinalPathTwo = FinalFilePath.Append((TEXT("%s"), *GameInstance->MyFighterName));

		FinalFilePath.Reset();

		FinalFilePath = FinalPathTwo.Append("'");

		UE_LOG(LogTemp, Warning, TEXT("%s"), *FinalFilePath);
		
		MovesInfo = LoadObject<UDataTable>(nullptr, (TEXT("%s"), *FinalFilePath));
	
		//MovesInfo = LoadObject<UDataTable>(nullptr, TEXT("'/Game/ThirdPersonCPP/Data/DT_KushaMoveset.DT_KushaMoveset'"));

		return MovesInfo;
	}
	return nullptr;
}
