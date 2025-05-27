// Copyright Arzu Mert

#include "UI/Widgets/DiceUserWidgetBase.h"
#include "Engine/Engine.h"

void UDiceUserWidgetBase::SetDiceWidgetController(UObject* InDiceWidgetController)
{
	DiceWidgetController = InDiceWidgetController;
	DiceWidgetControllerSet();
}

void UDiceUserWidgetBase::SetOverlayInteractionTarget(UObject* InOverlayInteractionTarget)
{
	OverlayInteractionTarget = InOverlayInteractionTarget;
	OverlayInteractionTargetSet();
}

void UDiceUserWidgetBase::ClearOverlayInteractionTarget()
{
	OverlayInteractionTarget = nullptr;
}







