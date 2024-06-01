#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SKGameMode.generated.h"

enum class EPointsEvent : uint8;
class UPointSystem;

UCLASS()
class SKSIMULATORGAME_API ASKGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	ASKGameMode();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	static ASKGameMode* GetSKGameMode(UWorld* World);
	
	virtual void NotifyPointSystem(EPointsEvent PointsEvent, float ScoreMultiplier = 1.0f);
	virtual UPointSystem* GetPointSystem() const { return PointSystem; }
	virtual float GetTotalTime() const { return Totaltime; }
protected:
	UPROPERTY(VisibleAnywhere)
	float Totaltime {0.0f};

protected:
	// Systems
	UPROPERTY(EditAnywhere)
	TSubclassOf<UPointSystem> PointSystemClass;
	UPROPERTY(EditAnywhere)
	UPointSystem* PointSystem {nullptr};
};
