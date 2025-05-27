// Copyright Arzu Mert


#include "UI/HUD/DiceHUD.h"
#include "UI/WidgetControllers/DiceWidgetController.h"
#include "UI/Widgets/DiceUserWidgetBase.h"


void ADiceHUD::InitDiceOverlay(APlayerController* PC, APlayerState* PS, UDiceRollComponent* DRC, TScriptInterface<IDiceTurnInterface> TMC)
{
	checkf(DiceWidgetControllerClass, TEXT("Dice Widget Controller Class uninitialized, please fill out BP_DiceHUD"));
	
	const FDiceWidgetControllerParams DiceWidgetControllerParams(PC, PS, DRC, TMC);
	DiceWidgetController = CreateDiceWidgetController(DiceWidgetControllerParams);
	DiceWidgetController->BroadcastInitialValues();
	CreateDiceOverlay(EOverlayType::EOT_Combat);
}

void ADiceHUD::CreateDiceOverlay(EOverlayType OverlayType)
{
	if (!OverlayInstances.Contains(OverlayType))
	{
		if (TSubclassOf<UUserWidget>* WidgetClass = OverlayWidgetClasses.Find(OverlayType))
		{
			UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), *WidgetClass);
			if (Widget)
			{
				if (UDiceUserWidgetBase* OverlayWidget = Cast<UDiceUserWidgetBase>(Widget))
				{
					OverlayWidget->SetDiceWidgetController(DiceWidgetController);
				}
				OverlayInstances.Add(OverlayType, Widget);
				Widget->SetVisibility(ESlateVisibility::Hidden);
			}
		}
	}
}

void ADiceHUD::ShowDiceOverlay(EOverlayType OverlayType, UObject* OverlayTarget)
{
	if (UUserWidget* Widget = *OverlayInstances.Find(OverlayType))
	{
		if (OverlayTarget)
		{
			if (UDiceUserWidgetBase* OverlayWidget = Cast<UDiceUserWidgetBase>(Widget))
			{
				OverlayWidget->SetOverlayInteractionTarget(OverlayTarget);
			}
		}
		if (!Widget->IsInViewport())
		{
			Widget->AddToViewport();
		}
		Widget->SetVisibility(ESlateVisibility::Visible);
	}
}

void ADiceHUD::HideDiceOverlay(EOverlayType OverlayType)
{
	if (UUserWidget** WidgetPtr = OverlayInstances.Find(OverlayType))
	{
		if (OverlayType == EOverlayType::EOT_None) return;
		
		if (UDiceUserWidgetBase* OverlayWidget = Cast<UDiceUserWidgetBase>(*WidgetPtr))
		{
			OverlayWidget->ClearOverlayInteractionTarget();
		}
		if (UUserWidget* Widget = *WidgetPtr)
		{
			Widget->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

UUserWidget* ADiceHUD::GetOverlayInstance(EOverlayType OverlayType) const
{
	return nullptr;
}

bool ADiceHUD::IsOverlayCreated(EOverlayType OverlayType) const
{
	return false;
}

UDiceWidgetController* ADiceHUD::CreateDiceWidgetController(const FDiceWidgetControllerParams& WCParams)
{
	if (DiceWidgetController == nullptr)
	{
		DiceWidgetController = NewObject<UDiceWidgetController>(this, DiceWidgetControllerClass);
		DiceWidgetController->SetWidgetControllerParams(WCParams);
		DiceWidgetController->BindCallbacksToDependencies();
		return DiceWidgetController;
	}
	return DiceWidgetController;
}