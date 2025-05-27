// Copyright Arzu Mert

#include "UI/WidgetControllers/DiceWidgetController.h"
#include "Components/DiceRollComponent.h"
#include "Interfaces/DiceTurnInterface.h"

void UDiceWidgetController::BroadcastInitialValues(){}

void UDiceWidgetController::BindCallbacksToDependencies()
{
	if (!DiceRollComponent) return;
	DiceRollComponent->OnDiceRolled.AddDynamic(this, &UDiceWidgetController::HandleDiceRolled);
	OnDiceUsed.AddDynamic(DiceRollComponent, &UDiceRollComponent::HandleDiceUsed);
	
	if (!DiceTurnInterface) return;
	OnTurnEnd.AddDynamic(this, &UDiceWidgetController::CallEndTurn);
	OnTurnStart.AddDynamic(this, &UDiceWidgetController::CallStartTurn);
}

void UDiceWidgetController::HandleDiceRolled()
{
	OnDiceRolledUI.Broadcast(DiceRollComponent->GetCurrentDice());
}

void UDiceWidgetController::HandleDiceUsed(const int32 UsedDie)
{
	OnDiceUsed.Broadcast(UsedDie);	
}

void UDiceWidgetController::HandleTurnEnd()
{
	OnTurnEnd.Broadcast();
}

void UDiceWidgetController::CallEndTurn()
{
	if (DiceTurnInterface)
	{
		DiceTurnInterface->Execute_EndActionTurn(DiceTurnInterface.GetObject());
	}
}

void UDiceWidgetController::HandleTurnStart()
{
	OnTurnStart.Broadcast();
}

void UDiceWidgetController::CallStartTurn()
{
	if (DiceTurnInterface)
	{
		DiceTurnInterface->Execute_StartActionTurn(DiceTurnInterface.GetObject());
	}
}
