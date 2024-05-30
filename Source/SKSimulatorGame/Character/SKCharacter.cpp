

#include "SKCharacter.h"

#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

ASKCharacter::ASKCharacter()
{
 	PrimaryActorTick.bCanEverTick = true;
	
	FrontSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Front Spring Arm"));
	FrontSpringArm->SetupAttachment(GetMesh());
	FrontSpringArm->TargetArmLength = 0.0f;
	FrontSpringArm->bDoCollisionTest = false;
	FrontSpringArm->bEnableCameraRotationLag = true;
	FrontSpringArm->CameraRotationLagSpeed = 15.0f;
	FrontSpringArm->SetRelativeLocation(FVector(30.0f, 0.0f, 120.0f));

	FrontCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Front Camera"));
	FrontCamera->SetupAttachment(FrontSpringArm);
	FrontCamera->bAutoActivate = true;

}

void ASKCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASKCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASKCharacter::OnMovement(const FInputActionValue& Value)
{
	FVector Direction = FVector(Value.Get<FVector2D >(),0.0f);
	AddMovementInput(Direction);
}

void ASKCharacter::OnJump(const FInputActionValue& Value)
{
	if (CanJump())
	{
		Jump();
	}
}

void ASKCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

