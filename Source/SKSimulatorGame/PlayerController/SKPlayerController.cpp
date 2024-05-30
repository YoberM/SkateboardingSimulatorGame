#include "SKPlayerController.h"

#include "EnhancedInputComponent.h"
#include "SKSimulatorGame/Character/SKCharacter.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"

void ASKPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}

void ASKPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &ASKPlayerController::OnMovement);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ASKPlayerController::OnJump);

	}	
}

void ASKPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	SKCharacter = Cast<ASKCharacter>(InPawn);
}

bool ASKPlayerController::CanDoAction()
{
	return SKCharacter->CanDoAction();
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
