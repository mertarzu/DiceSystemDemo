// Copyright Arzu Mert

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DiceRollComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDiceRolled);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DICESYSTEM_API UDiceRollComponent : public UActorComponent
{
	GENERATED_BODY()

public:		
	UDiceRollComponent();

	UFUNCTION(BlueprintCallable, Category = "Dice")
	void RollDice();

	UFUNCTION(BlueprintCallable, Category = "Dice")
	void RemoveUsedDice(int32 Value);

	UFUNCTION(BlueprintCallable, Category = "Dice")
	bool AreAllDiceUsed() const;
	
	UFUNCTION(BlueprintCallable, Category = "Dice")
	const TArray<int32>& GetCurrentDice() const { return CurrentDiceValues; }

	UFUNCTION(BlueprintCallable, Category = "Dice")
	int32 GetNumberOfDice() const { return NumberOfDice; }

	UFUNCTION()
	void HandleDiceUsed(const int32 UsedValue);

	FOnDiceRolled OnDiceRolled;
	
protected:

	UPROPERTY(EditDefaultsOnly, Category = "Dice")
	int32 NumberOfDice = 4;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Dice")
	int32 DieMinValue = 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Dice")
	int32 DieMaxValue = 6;
	
	UPROPERTY(EditAnywhere, Category = "Dice")
	bool IsUsingCustomSeed = false;

	UPROPERTY(EditAnywhere, Category = "Dice", meta = (EditCondition = "bUseCustomSeed"))
	int32 Seed = 12345;

	FRandomStream DiceRandomStream;

	TArray<int32> CurrentDiceValues;
};
