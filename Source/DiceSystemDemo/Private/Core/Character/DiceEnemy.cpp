// Copyright Arzu Mert


#include "Core/Character/DiceEnemy.h"
#include "Components/WidgetComponent.h"
#include "Components/SphereComponent.h"
#include "Interfaces/DiceInteractionInterface.h"
#include "Combat/DiceCombatComponent.h"
#include "Core/Character/DiceCharacter.h"
#include "Core/Player/DicePlayerController.h"
#include "UI/HUD/DiceHUD.h"


ADiceEnemy::ADiceEnemy()
{
	InteractionPromptWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InteractionPromptWidget"));
	InteractionPromptWidget->SetupAttachment(GetRootComponent());

	CombatComponent = CreateDefaultSubobject<UDiceCombatComponent>(TEXT("CombatComponent"));
}

UDiceCombatComponent* ADiceEnemy::GetCombatComponent_Implementation()
{
	return CombatComponent;
}

void ADiceEnemy::SetPromptVisibility_Implementation(bool IsVisible)
{
	if (InteractionPromptWidget)
	{
		InteractionPromptWidget->SetVisibility(IsVisible);
	}
}

void ADiceEnemy::BeginPlay()
{
	Super::BeginPlay();

	SetPromptVisibility_Implementation(false);

	if (InteractionSphere)
	{
		InteractionSphere->OnComponentBeginOverlap.AddDynamic(this, &ADiceEnemy::OnInteractionSphereBeginOverlap);
		InteractionSphere->OnComponentEndOverlap.AddDynamic(this, &ADiceEnemy::OnInteractionSphereEndOverlap);
	}
}

void ADiceEnemy::OnInteractionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	
	if (!OtherActor->Implements<UDiceInteractionInterface>()) return;
	IDiceInteractionInterface::Execute_SetOverlappingTarget(OtherActor, this);
	SetPromptVisibility_Implementation(true);
}

void ADiceEnemy::OnInteractionSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (!OtherActor->Implements<UDiceInteractionInterface>()) return;
	IDiceInteractionInterface::Execute_ClearOverlappingTarget(OtherActor, this);
	SetPromptVisibility_Implementation(false);
}