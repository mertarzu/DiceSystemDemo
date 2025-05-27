// Copyright Arzu Mert


#include "Core/Player/DicePlayerState.h"
#include "Components/DiceRollComponent.h"
#include "Components/DiceTurnManagerComponent.h"

ADicePlayerState::ADicePlayerState()
{
	DiceRollComponent = CreateDefaultSubobject<UDiceRollComponent>(TEXT("DiceRollComponent"));
	DiceTurnManagerComponent = CreateDefaultSubobject<UDiceTurnManagerComponent>(TEXT("DiceTurnManagerComponent"));
	DiceTurnManagerComponent->Initialize(DiceRollComponent);
}
