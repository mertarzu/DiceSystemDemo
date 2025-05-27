// Copyright Arzu Mert


#include "Core/Character/DiceCharacter.h"
#include "Core/Player/DicePlayerState.h"
#include "Core/Player/DicePlayerController.h"
#include "UI/HUD/DiceHUD.h"
#include "Components/DiceRollComponent.h"
#include "Components/DiceTurnManagerComponent.h"
#include "Interfaces/DiceTurnInterface.h"
#include "Interfaces/DiceInteractablePromptInterface.h"

ADiceCharacter::ADiceCharacter()
{
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void ADiceCharacter::SetOverlappingTarget_Implementation(UObject* Target)
{
	CurrentInteractableTarget = Target;
}

void ADiceCharacter::ClearOverlappingTarget_Implementation(UObject* Target)
{
	CurrentInteractableTarget = nullptr;
}

void ADiceCharacter::StartInteraction()
{
	if (!CurrentInteractableTarget) return;

	DicePlayerController = Cast<ADicePlayerController>(GetController());

	if (DicePlayerController)
	{
		DiceHUD = Cast<ADiceHUD>(DicePlayerController->GetHUD());
		if (DiceHUD)
		{
				DiceHUD->ShowDiceOverlay(EOverlayType::EOT_Combat, CurrentInteractableTarget);
				DicePlayerController->SetInputMode(FInputModeUIOnly());
				if (!CurrentInteractableTarget->Implements<UDiceInteractablePromptInterface>()) return;
				IDiceInteractablePromptInterface::Execute_SetPromptVisibility(CurrentInteractableTarget, false);
		}
	}
}

void ADiceCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	InitReferences();
	InitDiceInfo();	
}

void ADiceCharacter::InitReferences()
{
	DicePlayerState = GetPlayerState<ADicePlayerState>();
	DicePlayerController = Cast<ADicePlayerController>(GetController());

	if (DicePlayerController)
	{
		DiceHUD = Cast<ADiceHUD>(DicePlayerController->GetHUD());
	}
}

void ADiceCharacter::InitDiceInfo()
{
	if (!DicePlayerState || !DicePlayerController || !DiceHUD) return;

	UDiceRollComponent* DiceRollComponent = DicePlayerState->GetDiceRollComponent();
	UDiceTurnManagerComponent* TurnManagerComponent = DicePlayerState->GetTurnManager();
	
	if (!DiceRollComponent || !TurnManagerComponent) return;
	if (!TurnManagerComponent->Implements<UDiceTurnInterface>()) return;
	TScriptInterface<IDiceTurnInterface> DiceTurnInterface = TScriptInterface<IDiceTurnInterface>(TurnManagerComponent);
	DiceHUD->InitDiceOverlay(DicePlayerController, DicePlayerState, DiceRollComponent, DiceTurnInterface);
}
