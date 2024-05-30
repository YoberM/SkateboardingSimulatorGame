#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SKPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class ASKCharacter;
struct FInputActionValue;

UCLASS()
class SKSIMULATORGAME_API ASKPlayerController : public APlayerController
{
	GENERATED_BODY()
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	virtual void OnPossess(APawn* InPawn) override;
	virtual	void OnMovement(const FInputActionValue& Value);
	virtual	void OnJump(const FInputActionValue& Value);

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MovementAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* JumpAction;
	
	TObjectPtr<ASKCharacter> SKCharacter;
};
