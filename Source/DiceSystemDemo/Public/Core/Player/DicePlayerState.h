// Copyright Arzu Mert

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "DicePlayerState.generated.h"

class UDiceRollComponent;
class UDiceTurnManagerComponent;

UCLASS()
class DICESYSTEMDEMO_API ADicePlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	ADicePlayerState();

	UFUNCTION(BlueprintCallable, Category = "Components")
	UDiceRollComponent* GetDiceRollComponent() const { return DiceRollComponent; }

	UFUNCTION(BlueprintCallable, Category = "Components")
	UDiceTurnManagerComponent* GetTurnManager() const { return DiceTurnManagerComponent; }
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UDiceRollComponent> DiceRollComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UDiceTurnManagerComponent> DiceTurnManagerComponent;
};
