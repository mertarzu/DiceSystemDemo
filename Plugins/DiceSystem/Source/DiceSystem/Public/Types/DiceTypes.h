// Copyright Arzu Mert

#pragma once

UENUM(BlueprintType)
enum class EDiceOutcome : uint8
{
	EDO_OutcomeFail UMETA(DisplayName = "OutcomeFail"),
	EDO_OutcomeNormal UMETA(DisplayName = "OutcomeNormal"),
	EDO_OutcomeStrong UMETA(DisplayName = "OutcomeStrong")
};