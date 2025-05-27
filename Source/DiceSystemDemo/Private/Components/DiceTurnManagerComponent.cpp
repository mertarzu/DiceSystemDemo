// Copyright Arzu Mert


#include "Components/DiceTurnManagerComponent.h"
#include "Components/DiceRollComponent.h"

UDiceTurnManagerComponent::UDiceTurnManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UDiceTurnManagerComponent::Initialize(UDiceRollComponent* InDiceRollComponent)
{
	DiceRollComponent = InDiceRollComponent;
}

void UDiceTurnManagerComponent::StartActionTurn_Implementation()
{
	if (IsTurnStarted || !DiceRollComponent) return;

	CurrentTurnPhase = ETurnPhase::ETP_RollingDice;
	IsTurnStarted = true;

	DiceRollComponent->RollDice();
}

void UDiceTurnManagerComponent::EndActionTurn_Implementation()
{
	if (!IsTurnStarted || !DiceRollComponent) return;

	CurrentTurnPhase = ETurnPhase::ETP_TurnEnded;
	IsTurnStarted = false;
	
}

bool UDiceTurnManagerComponent::IsPlayerTurn_Implementation() const
{
	return IsTurnStarted;
}



