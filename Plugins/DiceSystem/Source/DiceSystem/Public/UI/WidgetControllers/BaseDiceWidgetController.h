// Copyright Arzu Mert

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseDiceWidgetController.generated.h"

class UDiceRollComponent;
class IDiceTurnInterface;


USTRUCT(BlueprintType)
struct FDiceWidgetControllerParams
{
	GENERATED_BODY()

	FDiceWidgetControllerParams() {}
	FDiceWidgetControllerParams(APlayerController* PC, APlayerState* PS, UDiceRollComponent* DRC, TScriptInterface<IDiceTurnInterface> TMI)
		: PlayerController(PC), PlayerState(PS), DiceRollComponent(DRC), DiceTurnInterface(TMI)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerState> PlayerState = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UDiceRollComponent> DiceRollComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TScriptInterface<IDiceTurnInterface> DiceTurnInterface;
};

UCLASS()
class DICESYSTEM_API UBaseDiceWidgetController : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetControllerParams(const FDiceWidgetControllerParams& WCParams);
	virtual void BroadcastInitialValues();
	virtual void BindCallbacksToDependencies();
protected:
	UPROPERTY(BlueprintReadOnly, Category = "DiceWidgetController")
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(BlueprintReadOnly, Category = "DiceWidgetController")
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY(BlueprintReadOnly, Category = "DiceWidgetController")
	TObjectPtr<UDiceRollComponent> DiceRollComponent;

	UPROPERTY(BlueprintReadOnly, Category = "DiceWidgetController")
	TScriptInterface<IDiceTurnInterface> DiceTurnInterface;
};
