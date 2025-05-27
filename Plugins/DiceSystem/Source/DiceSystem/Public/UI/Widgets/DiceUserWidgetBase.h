// Copyright Arzu Mert

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Data/DiceData.h"
#include "DiceUserWidgetBase.generated.h"


UCLASS()
class DICESYSTEM_API UDiceUserWidgetBase : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetDiceWidgetController(UObject* InDiceWidgetController);

	UFUNCTION(BlueprintCallable)
	void SetOverlayInteractionTarget(UObject* InOverlayInteractionTarget);

	UFUNCTION(BlueprintCallable, Category = "UI")
	void ClearOverlayInteractionTarget();

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> DiceWidgetController;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> OverlayInteractionTarget;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "UI")
	void DiceWidgetControllerSet();

	UFUNCTION(BlueprintImplementableEvent)
	void OverlayInteractionTargetSet();
};
