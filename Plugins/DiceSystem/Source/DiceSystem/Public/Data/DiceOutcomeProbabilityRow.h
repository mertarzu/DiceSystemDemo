// Copyright Arzu Mert

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DiceOutcomeProbabilityRow.generated.h"

USTRUCT(BlueprintType)
struct FDiceOutcomeProbabilityRow : public FTableRowBase
{
	GENERATED_BODY()

	// Chance values should be in 0.0 to 1.0 range
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FailChance = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float NormalChance = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float StrongChance = 0.0f;
};

