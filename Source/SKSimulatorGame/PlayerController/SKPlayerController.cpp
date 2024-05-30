#include "SKPlayerController.h"

#include "EnhancedInputComponent.h"
#include "SKSimulatorGame/Character/SKCharacter.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"

void ASKPlayerController::BeginPlay()
{
	Super::BeginPlay();
	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}

void ASKPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// steering 
		EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &ASKPlayerController::OnMovement);

		// throttle 
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ASKPlayerController::OnJump);

	}	
}

void ASKPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	SKCharacter = Cast<ASKCharacter>(InPawn);
}

void ASKPlayerController::OnMovement(const FInputActionValue& Value)
{
	FVector2D BreakValue = Value.Get<FVector2D>();
	SKCharacter->OnMovement(Value);
}

void ASKPlayerController::OnJump(const FInputActionValue& Value)
{
	SKCharacter->OnJump(Value);
}
