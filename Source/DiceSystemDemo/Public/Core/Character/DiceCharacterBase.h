// Copyright Arzu Mert

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DiceCharacterBase.generated.h"

class USphereComponent;
class ADicePlayerState;
class ADicePlayerController;
class ADiceHUD;

UCLASS()
class DICESYSTEMDEMO_API ADiceCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ADiceCharacterBase();
protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> InteractionSphere;

	UPROPERTY()
	TObjectPtr<ADicePlayerState> DicePlayerState;

	UPROPERTY()
	TObjectPtr<ADicePlayerController> DicePlayerController;

	UPROPERTY()
	TObjectPtr<ADiceHUD> DiceHUD;
};
