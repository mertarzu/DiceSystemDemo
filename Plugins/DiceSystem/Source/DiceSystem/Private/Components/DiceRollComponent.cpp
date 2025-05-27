// Copyright Arzu Mert

#include "Components/DiceRollComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/RandomStream.h"

UDiceRollComponent::UDiceRollComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UDiceRollComponent::RollDice()
{
	CurrentDiceValues.Empty(NumberOfDice);

	if (IsUsingCustomSeed)
	{
		DiceRandomStream.Initialize(Seed);

		for (int32 i = 0; i < NumberOfDice; ++i)
		{
			const int32 Rolled = DiceRandomStream.RandRange(DieMinValue, DieMaxValue);
			CurrentDiceValues.Add(Rolled);
		}
	}
	else
	{
		for (int32 i = 0; i < NumberOfDice; ++i)
		{
			const int32 Rolled = FMath::RandRange(DieMinValue, DieMaxValue);
			CurrentDiceValues.Add(Rolled);
		}
	}

	OnDiceRolled.Broadcast();
}

void UDiceRollComponent::RemoveUsedDice(int32 Value)
{
	CurrentDiceValues.RemoveSingle(Value);
}

bool UDiceRollComponent::AreAllDiceUsed() const
{
	return CurrentDiceValues.Num() == 0;
}

void UDiceRollComponent::HandleDiceUsed(const int32 UsedValue)
{
	RemoveUsedDice(UsedValue);
}








