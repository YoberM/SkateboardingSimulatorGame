

#include "SKCharacter.h"

#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"



ASKCharacter::ASKCharacter()
{
 	PrimaryActorTick.bCanEverTick = true;
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Front Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 0.0f;
	SpringArm->bDoCollisionTest = false;
	SpringArm->bEnableCameraRotationLag = true;
	SpringArm->CameraRotationLagSpeed = 15.0f;
	SpringArm->SetRelativeLocation(FVector(30.0f, 0.0f, 120.0f));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Front Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->bAutoActivate = true;

}

void ASKCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ASKCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Velocity = GetVelocity();
}

bool ASKCharacter::CanDoAction()
{
	switch (CharacterState)
	{
	case ESKCharacterState::Waiting:
		return false;
		break;
	default:
		return true;
	}
	// Safe case
	return false;
}

bool ASKCharacter::CanDoMovement()
{
	switch (CharacterState)
	{
	case ESKCharacterState::AttachedToObstacle:
		return false;
		break;
	case ESKCharacterState::Idle:
	case ESKCharacterState::Moving:
	case ESKCharacterState::Jumping:
		return true;
		break;
	default:
		return false;
	}
	// Safe case
	return false;
}

bool ASKCharacter::CanDoJump()
{
	switch (CharacterState)
	{
	case ESKCharacterState::Jumping:
	case ESKCharacterState::Waiting:
		return false;
		break;
	default:
		return true;
		break;
	}
	// Safe case
	return false;
}

void ASKCharacter::OnMovement(const FInputActionValue& Value)
{
	if (CanDoAction())
	{
		FVector Direction = FVector(Value.Get<FVector2D>(),0.0f);
	    FVector ForwardDirection = GetActorForwardVector() * Direction.X;
		GetMovementComponent()->AddInputVector(ForwardDirection);
		AddActorLocalRotation(FRotator(0, Direction.Y * CalculateRotation(Value),0),false,nullptr,ETeleportType::TeleportPhysics);
	}
	else
	{
		
	}
}

float ASKCharacter::CalculateRotation(const FInputActionValue& Value)
{
	float VelocityRate = GetVelocity().Size2D() / GetMovementComponent()->GetMaxSpeed();
	float RotationRate = FMath::InterpEaseIn(MinRotationFactor,MaxRotationFactor,VelocityRate,2);
	return RotationRate;
}

void ASKCharacter::OnJump(const FInputActionValue& Value)
{
	if (CanJump())
	{
		Jump();
		OnJumpEvent.Broadcast();
	}
	else
	{
		// Something like wrong audios	
	}
}

void ASKCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASKCharacter::SetCharacterState(ESKCharacterState NewCharacterState)
{
	switch (CharacterState)
	{
	case ESKCharacterState::Idle:
		// Do Something
		break;
	case ESKCharacterState::Moving:
		break;
	case ESKCharacterState::Jumping:
		break;
	case ESKCharacterState::AttachedToObstacle:
		break;
	}
	CharacterState = NewCharacterState;
}

