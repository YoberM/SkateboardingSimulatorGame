#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SKCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnJumpEvent);

class UInputAction;
struct FInputActionValue;
class UInputComponent;
class UCameraComponent;
class USpringArmComponent;
class ABaseObstacle;

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
	float MinRotationFactor { 1.0f };
	UPROPERTY(EditAnywhere)
	float MaxRotationFactor { 1.0f };
	UPROPERTY(EditAnywhere)
	float HighVelocityFactor { 0.8f };
	
	UPROPERTY(EditAnywhere)
	float ReattachmentDelay { 0.25f };
	UPROPERTY(EditAnywhere)
	float ReattachmentDelayDT { 0.0f };
	
	UPROPERTY(EditAnywhere)
	TWeakObjectPtr<ABaseObstacle> AttachedObstacle { nullptr };

	UPROPERTY(EditAnywhere)
	ESKCharacterState CharacterState { ESKCharacterState::Idle };


	UPROPERTY(BlueprintAssignable)
	FOnJumpEvent OnJumpEvent;

	ASKCharacter();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual bool CanDoAction();
	virtual bool CanDoMovement();
	virtual bool CanDoJump();
	virtual void HandleReattachment(float DeltaTime);
	virtual void HandleVelocity(float DeltaTime);
	virtual	void OnHighVelocity(float DeltaTime);
	virtual	void OnMovement(const FInputActionValue& Value);
	virtual	float CalculateRotation(const FInputActionValue& Value);
	virtual	void OnJump(const FInputActionValue& Value);

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	ESKCharacterState GetCharacterState() const { return CharacterState; }
	void SetCharacterState(ESKCharacterState NewCharacterState);
	ABaseObstacle* GetAttachToObstacle() { return AttachedObstacle.Get(); };
	void SetAttachToObstacle(ABaseObstacle* Obstacle);
};
