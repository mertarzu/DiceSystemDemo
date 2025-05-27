// Copyright Arzu Mert

#pragma once


#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Types/DiceTypes.h"
#include "Engine/DataTable.h"
#include "DiceResolutionLibrary.generated.h"

UCLASS()
class DICESYSTEM_API UDiceResolutionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "DiceSystem")
	static EDiceOutcome ResolveOutcomeFromDataTable(
		int32 DieValue,
		const UDataTable* OutcomeProbabilityTable
	);
};
