#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SKCharacter.generated.h"

class UInputAction;
struct FInputActionValue;
class UInputComponent;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class SKSIMULATORGAME_API ASKCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	/** Front Camera component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FrontCamera;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* FrontSpringArm;

	ASKCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual	void OnMovement(const FInputActionValue& Value);
	virtual	void OnJump(const FInputActionValue& Value);

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
};
