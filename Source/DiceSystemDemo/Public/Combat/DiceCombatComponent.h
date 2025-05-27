// Copyright Arzu Mert

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Types/DiceTypes.h"
#include "DiceCombatComponent.generated.h"

USTRUCT(BlueprintType)
struct FCombatDamageProfile
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 DamageOnFail = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 DamageOnNormal = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 DamageOnStrong = 25;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DICESYSTEMDEMO_API UDiceCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UDiceCombatComponent();

	UFUNCTION(BlueprintCallable, Category = "Combat")
	int32 ResolveDie(int32 DieValue) const;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	class UDataTable* CombatOutcomeProbabilityTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	FCombatDamageProfile DamageProfile;

	int32 GetDamageFromOutcome(EDiceOutcome Outcome) const;

};
