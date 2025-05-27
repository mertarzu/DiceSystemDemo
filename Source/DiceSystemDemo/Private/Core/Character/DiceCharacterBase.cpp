// Copyright Arzu Mert


#include "Core/Character/DiceCharacterBase.h"
#include "Components/SphereComponent.h"


ADiceCharacterBase::ADiceCharacterBase()
{
	InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	InteractionSphere->SetupAttachment(GetRootComponent());
}