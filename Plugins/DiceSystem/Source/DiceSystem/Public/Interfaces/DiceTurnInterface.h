#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DiceTurnInterface.generated.h"

UINTERFACE(Blueprintable)
class DICESYSTEM_API UDiceTurnInterface : public UInterface
{
	GENERATED_BODY()
};

class DICESYSTEM_API IDiceTurnInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Turn System")
	void StartActionTurn();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Turn System")
	void EndActionTurn();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Turn System")
	bool IsPlayerTurn() const;
};

