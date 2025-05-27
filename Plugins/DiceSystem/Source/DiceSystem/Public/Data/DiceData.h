// Copyright Arzu Mert
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Styling/SlateBrush.h"
#include "DiceData.generated.h"

USTRUCT(BlueprintType)
struct FDiceData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dice")
	int32 DiceValue = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dice")
	FSlateBrush DiceImage;
};
