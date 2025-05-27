// Copyright Arzu Mert

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DicePlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class DICESYSTEMDEMO_API ADicePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ADicePlayerController();
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputMappingContext> CharacterMappingContext;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputAction> InteractAction;

	void Move(const FInputActionValue& Value);
	void Interact();
};