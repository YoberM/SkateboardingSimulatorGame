#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SKCharacter.generated.h"

UCLASS()
class SKSIMULATORGAME_API ASKCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASKCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
