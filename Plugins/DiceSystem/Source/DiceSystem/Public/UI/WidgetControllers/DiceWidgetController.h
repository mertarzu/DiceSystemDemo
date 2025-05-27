// Copyright Arzu Mert

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetControllers/BaseDiceWidgetController.h"
#include "DiceWidgetController.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDiceRolledUI, const TArray<int32>&, RolledDice);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDiceUsed, const int32, UsedDie);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDiceDragAvailable, bool, IsAvailable);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTurnEnd);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTurnStart);


UCLASS(BlueprintType, Blueprintable)
class DICESYSTEM_API UDiceWidgetController : public UBaseDiceWidgetController
{
	GENERATED_BODY()
public:

	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnDiceRolledUI OnDiceRolledUI;

	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnDiceUsed OnDiceUsed;

	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnDiceDragAvailable OnDiceDragAvailable;

	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnTurnEnd OnTurnEnd;

	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnTurnEnd OnTurnStart;

	UFUNCTION()
	void HandleDiceRolled();
	
	UFUNCTION(BlueprintCallable, Category = "Dice")
	void HandleDiceUsed(const int32 UsedDie);

	UFUNCTION(BlueprintCallable, Category = "Dice")
	void HandleTurnEnd();

	UFUNCTION(BlueprintCallable, Category = "Dice")
	void CallEndTurn();
	UFUNCTION(BlueprintCallable, Category = "Dice")
	void HandleTurnStart();

	UFUNCTION(BlueprintCallable, Category = "Dice")
	void CallStartTurn();
};
