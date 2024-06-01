#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SKGameMode.generated.h"

UCLASS()
class SKSIMULATORGAME_API ASKGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	ASKGameMode();
	virtual void Tick(float DeltaSeconds) override;
	static ASKGameMode* GetSKGameMode(UWorld* World);

	virtual float GetTotalTime() const { return Totaltime; }
protected:
	UPROPERTY(VisibleAnywhere)
	float Totaltime {0.0f};
};
