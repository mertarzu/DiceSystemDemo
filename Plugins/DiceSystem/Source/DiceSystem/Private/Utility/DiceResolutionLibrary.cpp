// Copyright Arzu Mert

#include "Utility/DiceResolutionLibrary.h"
#include "Data/DiceOutcomeProbabilityRow.h"

EDiceOutcome UDiceResolutionLibrary::ResolveOutcomeFromDataTable(int32 DieValue, const UDataTable* OutcomeProbabilityTable)
{
	if (!OutcomeProbabilityTable || DieValue < 1 || DieValue > 6)
	{
		return EDiceOutcome::EDO_OutcomeFail;
	}

	const FString RowKey = FString::FromInt(DieValue);
	const FDiceOutcomeProbabilityRow* Row = OutcomeProbabilityTable->FindRow<FDiceOutcomeProbabilityRow>(*RowKey, TEXT("ResolveOutcome"));

	if (!Row)
	{
		return EDiceOutcome::EDO_OutcomeFail;
	}

	const float Roll = FMath::FRand();
	
	if (Roll <= Row->FailChance)
	{
		return EDiceOutcome::EDO_OutcomeFail;
	}
	else if (Roll <= Row->FailChance + Row->NormalChance)
	{
		return EDiceOutcome::EDO_OutcomeNormal;
	}
	else
	{
		return EDiceOutcome::EDO_OutcomeStrong;
	}
}
