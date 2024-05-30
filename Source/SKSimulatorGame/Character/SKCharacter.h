#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SKCharacter.generated.h"

class UInputAction;
struct FInputActionValue;
class UInputComponent;
class UCameraComponent;
class USpringArmComponent;

UENUM()
enum class ESKCharacterState : uint8
{
	Idle,
	Moving,
	Jumping,
	AttachedToObstacle,
	Waiting
};

UCLASS()
class SKSIMULATORGAME_API ASKCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	/** Front Camera component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"),Transient)
	UCameraComponent* Camera;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"),Transient)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
	float RotationFactor { 1.0f };

	UPROPERTY(EditAnywhere)
	ESKCharacterState CharacterState { ESKCharacterState::Idle };

	ASKCharacter();

protected:
	virtual void BeginPlay() override;

public:
	
	virtual void Tick(float DeltaTime) override;
	virtual bool CanDoAction();
	virtual bool CanDoMovement();
	virtual bool CanDoJump();
	virtual	void OnMovement(const FInputActionValue& Value);
	virtual	void OnJump(const FInputActionValue& Value);

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	ESKCharacterState GetCharacterState() const { return CharacterState; }
	void SetCharacterState(ESKCharacterState NewCharacterState);
};
