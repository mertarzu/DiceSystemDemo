// Copyright Arzu Mert


#include "Core/Player/DicePlayerController.h"
#include "Core/Character/DiceCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"

ADicePlayerController::ADicePlayerController(){}

void ADicePlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(CharacterMappingContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->ClearAllMappings();
		Subsystem->AddMappingContext(CharacterMappingContext, 0);
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameOnly InputModeData;
	SetInputMode(InputModeData);
}

void ADicePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	check(EnhancedInputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADicePlayerController::Move);
	EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &ADicePlayerController::Interact);
}

void ADicePlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, MovementVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ADicePlayerController::Interact()
{
	ADiceCharacter* DiceCharacter = Cast<ADiceCharacter>(GetPawn());
	if (DiceCharacter)
	{
		DiceCharacter->StartInteraction();	
	}
}