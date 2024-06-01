#include "SKPlayerController.h"
#include "EnhancedInputComponent.h"
#include "SKSimulatorGame/Character/SKCharacter.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"
#include "SKSimulatorGame/Gamemode/SKGameMode.h"
#include "SKSimulatorGame/PointSystem/PointSystem.h"
#include "SKSimulatorGame/UI/Controller/SKPlayerUIController.h"

void ASKPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
	if (PlayerUIControllerClass)
	{
		PlayerUIControllerInstance = NewObject<USKPlayerUIController>(this,PlayerUIControllerClass);
		PlayerUIControllerInstance->Initialize(this);
	}
}

void ASKPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (PlayerUIControllerInstance)
	{
		// Temporally set score to 0
		PlayerUIControllerInstance->UpdateSpeed(SKCharacter->GetVelocity().Size());
		// Global properties
		if (ASKGameMode* GameMode = ASKGameMode::GetSKGameMode(GetWorld()))
		{
			PlayerUIControllerInstance->UpdateScore(GameMode->GetPointSystem()->GetScore());
			PlayerUIControllerInstance->UpdateTotalTime(GameMode->GetTotalTime());
		}
	}
}

void ASKPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &ASKPlayerController::OnMovement);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ASKPlayerController::OnJump);

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
