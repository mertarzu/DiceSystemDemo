// Copyright Arzu Mert

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DiceInteractablePromptInterface.generated.h"

UINTERFACE(Blueprintable)
class UDiceInteractablePromptInterface : public UInterface
{
	GENERATED_BODY()
};


class DICESYSTEMDEMO_API IDiceInteractablePromptInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetPromptVisibility(bool IsVisible);
};
