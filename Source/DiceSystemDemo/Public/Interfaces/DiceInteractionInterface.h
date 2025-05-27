// Copyright Arzu Mert

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DiceInteractionInterface.generated.h"


UINTERFACE(Blueprintable)
class UDiceInteractionInterface : public UInterface
{
	GENERATED_BODY()
};


class DICESYSTEMDEMO_API IDiceInteractionInterface
{
	GENERATED_BODY()

	
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetOverlappingTarget(UObject* Target);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ClearOverlappingTarget(UObject* Target);
};
