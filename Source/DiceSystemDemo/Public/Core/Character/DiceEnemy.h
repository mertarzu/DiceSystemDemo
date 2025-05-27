// Copyright Arzu Mert

#pragma once

#include "CoreMinimal.h"
#include "Combat/DiceCombatInteractionInterface.h"
#include "Interfaces/DiceInteractablePromptInterface.h"
#include "Core/Character/DiceCharacterBase.h"
#include "DiceEnemy.generated.h"

class UWidgetComponent;
class UDiceCombatComponent;

UCLASS()
class DICESYSTEMDEMO_API ADiceEnemy : 
	public ADiceCharacterBase, 
	public IDiceCombatInteractionInterface,
	public IDiceInteractablePromptInterface
{
	GENERATED_BODY()
public:
	ADiceEnemy();
	virtual UDiceCombatComponent* GetCombatComponent_Implementation() override;
	virtual void SetPromptVisibility_Implementation(bool IsVisible) override;
protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnInteractionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void OnInteractionSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UWidgetComponent> InteractionPromptWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UDiceCombatComponent> CombatComponent;
};
