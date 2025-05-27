// Copyright Arzu Mert

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/DiceTurnInterface.h"
#include "GameFramework/HUD.h"
#include "DiceHUD.generated.h"

struct FDiceWidgetControllerParams;
class UDiceRollComponent;
class UDiceWidgetController;
class UDiceUserWidgetBase;

UENUM(BlueprintType)
enum class EOverlayType : uint8
{
	EOT_None UMETA(DisplayName = "None"),
	EOT_Combat UMETA(DisplayName = "Combat")
};


UCLASS()
class DICESYSTEMDEMO_API ADiceHUD : public AHUD
{
	GENERATED_BODY()
public:
	void InitDiceOverlay(APlayerController* PC, APlayerState* PS, UDiceRollComponent* DRC, TScriptInterface<IDiceTurnInterface> TMC);
	UDiceWidgetController* GetDiceWidgetController()const { return DiceWidgetController; }

	UFUNCTION(BlueprintCallable)
	void CreateDiceOverlay(EOverlayType OverlayType);

	UFUNCTION(BlueprintCallable, Category = "UI")
	void ShowDiceOverlay(EOverlayType OverlayType, UObject* OverlayTarget);

	UFUNCTION(BlueprintCallable, Category = "UI")
	void HideDiceOverlay(EOverlayType OverlayType);

	UFUNCTION(BlueprintCallable, Category = "UI")
	UUserWidget* GetOverlayInstance(EOverlayType OverlayType) const;

	UFUNCTION(BlueprintPure, Category = "UI")
	bool IsOverlayCreated(EOverlayType OverlayType) const;
protected:
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TMap<EOverlayType, TSubclassOf<UUserWidget>> OverlayWidgetClasses;

	UPROPERTY()
	TMap<EOverlayType, UUserWidget*> OverlayInstances;
private:
	UDiceWidgetController* CreateDiceWidgetController(const FDiceWidgetControllerParams& WCParams);
	
	UPROPERTY()
	TObjectPtr<UDiceWidgetController> DiceWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UDiceWidgetController> DiceWidgetControllerClass;
};