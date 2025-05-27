// Copyright Arzu Mert

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interfaces/DiceOverlayContentContextInterface.h"
#include "DiceCombatInteractionInterface.generated.h"

class UDiceCombatComponent;

UINTERFACE(MinimalAPI, Blueprintable)
class UDiceCombatInteractionInterface : public UDiceOverlayContentContextInterface
{
	GENERATED_BODY()
	
};


class DICESYSTEMDEMO_API IDiceCombatInteractionInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	UDiceCombatComponent* GetCombatComponent();
};
