// Copyright Arzu Mert


#include "Combat/DiceCombatComponent.h"
#include "Utility/DiceResolutionLibrary.h"

UDiceCombatComponent::UDiceCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

int32 UDiceCombatComponent::ResolveDie(int32 DieValue) const
{
	if (!CombatOutcomeProbabilityTable) return 0;
	
	const EDiceOutcome Outcome = UDiceResolutionLibrary::ResolveOutcomeFromDataTable(
		DieValue,
		CombatOutcomeProbabilityTable
	);

	return GetDamageFromOutcome(Outcome);
}

int32 UDiceCombatComponent::GetDamageFromOutcome(EDiceOutcome Outcome) const
{
	switch (Outcome)
	{
	case EDiceOutcome::EDO_OutcomeFail:
		return DamageProfile.DamageOnFail;
	case EDiceOutcome::EDO_OutcomeNormal:
		return DamageProfile.DamageOnNormal;
	case EDiceOutcome::EDO_OutcomeStrong:
		return DamageProfile.DamageOnStrong;
	default:
		return 0;
	}
}





