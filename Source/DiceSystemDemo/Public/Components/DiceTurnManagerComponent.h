// Copyright Arzu Mert

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/DiceTurnInterface.h"
#include "Components/ActorComponent.h"
#include "DiceTurnManagerComponent.generated.h"

class UDiceRollComponent;

UENUM(BlueprintType)
enum class ETurnPhase : uint8
{
	ETP_RollingDice UMETA(DisplayName = "RollingDice"),
	ETP_TakingActions UMETA(DisplayName = "TakingActions"),
	ETP_ResolvingActions UMETA(DisplayName = "ResolvingActions"),
	ETP_TurnEnded UMETA(DisplayName = "TurnEnded")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DICESYSTEMDEMO_API UDiceTurnManagerComponent : public UActorComponent, public IDiceTurnInterface
{
	GENERATED_BODY()

public:	
	UDiceTurnManagerComponent();
	void Initialize(UDiceRollComponent* InDiceRollComponent);

	virtual void StartActionTurn_Implementation() override;
	virtual void EndActionTurn_Implementation() override;
	virtual bool IsPlayerTurn_Implementation() const override;

	ETurnPhase GetCurrentPhase() const { return CurrentTurnPhase; }

private:
	UPROPERTY()
	TObjectPtr<UDiceRollComponent> DiceRollComponent;

	ETurnPhase CurrentTurnPhase = ETurnPhase::ETP_TurnEnded;
	bool IsTurnStarted = false;
};
