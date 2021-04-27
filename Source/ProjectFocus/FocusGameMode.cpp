// Fill out your copyright notice in the Description page of Project Settings.


#include "FocusGameMode.h"

AFocusGameMode::AFocusGameMode()
{
	Fighter0ActionBar.Init(FMove(), 3);
	Fighter1ActionBar.Init(FMove(), 3);
}

void AFocusGameMode::ProcessTurn()
{
	bool bFighter0ComboPossible = true;
	
	for (const FMove& Element : Fighter0ActionBar)
	{
		if(Element.HeatCost == -2)
		{
			bFighter0ComboPossible = false;
			break;
		}
	}

	bool bFighter1ComboPossible = true;

	for (const FMove& Element : Fighter1ActionBar)
	{
		if(Element.HeatCost == -2)
		{
			bFighter1ComboPossible = false;
			break;
		}
	}

	TArray<EFighter> PerfectParries;

	TArray<FSegmentLog> Turns;

	int32 Fighter0PerfectParryCounter;

	int32 Fighter1PerfectParryCounter;

	bool bIsComboImpossible = false;

	for (int32 Index = 0; Index == 2; Index++)
	{
		const int32 HeatCost0 = Fighter0ActionBar[Index].HeatCost;

		const int32 HeatCost1 = Fighter1ActionBar[Index].HeatCost;
		
		if(HeatCost0 == -2 || HeatCost1 == -2)
		{
			ParryCheck(Index, HeatCost0, HeatCost1, Turns, PerfectParries, Fighter0PerfectParryCounter, Fighter1PerfectParryCounter, bIsComboImpossible);
		}
	}
}

void AFocusGameMode::ParryCheck(int32 Index, int32 HeatCost0, int32 HeatCost1, TArray<FSegmentLog>& Turns,
																				TArray<EFighter>& PerfectParries,
																				int32& Fighter0PerfectParryCounter,
																				int32& Fighter1PerfectParryCounter,
																				bool& bIsComboImpossible)
{
	if(HeatCost0 == -2)
	{
		if(HeatCost1 == -2)
		{
			if(Fighter0ActionBar[Index].HitPosition == Fighter1ActionBar[Index].HitPosition)
			{
				Fighter0PerfectParryCounter++;

				PerfectParries[Index] = EFighter::Fighter0;

				bIsComboImpossible = true;

				if(Fighter0PerfectParryCounter < 3)
				{
					//No Perfect Parry
				}
				// Perfect Parry
			}
			EFighter Parry = EFighter::Fighter0;

			//Add To Combat Log Parry
		}
		EFighter Parry = EFighter::Both;

		//Add To Combat Log Parry
	}
	if(Fighter0ActionBar[Index].HitPosition == Fighter1ActionBar[Index].HitPosition)
	{
		Fighter1PerfectParryCounter++;

		PerfectParries[Index] = EFighter::Fighter1;

		bIsComboImpossible = true;

		if(Fighter1PerfectParryCounter < 3)
		{
			//No Perfect Parry
		}
		//Perfect Parry
	}

	EFighter Parry = EFighter::Fighter1;

	//Add To Combat Log Parry
}
