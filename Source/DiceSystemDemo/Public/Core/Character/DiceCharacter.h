// Copyright Arzu Mert

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/DiceInteractionInterface.h"
#include "Core/Character/DiceCharacterBase.h"
#include "DiceCharacter.generated.h"


UCLASS()
class DICESYSTEMDEMO_API ADiceCharacter : public ADiceCharacterBase, public IDiceInteractionInterface
{
	GENERATED_BODY()
public:
	ADiceCharacter();
	virtual void SetOverlappingTarget_Implementation(UObject* Target) override;
	virtual void ClearOverlappingTarget_Implementation(UObject* Target) override;
	void StartInteraction();
	
protected:
	virtual void BeginPlay() override;
private:
	void InitReferences();
	void InitDiceInfo();
	UObject* CurrentInteractableTarget;
};
