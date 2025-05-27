// Copyright Arzu Mert

#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DiceOverlayContentContextInterface.generated.h"

UINTERFACE(Blueprintable)
class DICESYSTEM_API UDiceOverlayContentContextInterface : public UInterface
{
	GENERATED_BODY()
};

class DICESYSTEM_API IDiceOverlayContentContextInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FName GetContentContextTag();
};
