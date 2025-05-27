// Copyright Arzu Mert


#include "UI/WidgetControllers/BaseDiceWidgetController.h"

void UBaseDiceWidgetController::SetWidgetControllerParams(const FDiceWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	DiceRollComponent = WCParams.DiceRollComponent;
	DiceTurnInterface = WCParams.DiceTurnInterface;
}

void UBaseDiceWidgetController::BroadcastInitialValues(){}

void UBaseDiceWidgetController::BindCallbacksToDependencies(){}


