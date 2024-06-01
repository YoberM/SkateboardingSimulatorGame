
#pragma once

#include "CoreMinimal.h"
#include "PointSystem.generated.h"

class ASKCharacter;

USTRUCT()
struct FPointsStruct
{
	GENERATED_BODY()
	UPROPERTY()
	float Score {0};
	// This could handle points for any difficulty
	UPROPERTY()
	float GlobalScoreMultiplier { 1.0f };
	// Possibility to handle multiple characters/players
	UPROPERTY()
	ASKCharacter* SKCharacter {nullptr};

	float GetScore() const { return Score * GlobalScoreMultiplier; }
};
USTRUCT()
struct FPointEventStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	float PointsToAddToScore { 0 };
	UPROPERTY(EditAnywhere)
	float Multiplier { 1.0f };
};

UENUM()
enum class EPointsEvent : uint8
{
	None,
	ObstacleAttached,
	JumpOnAttachedObstacle,
	HighVelocity,
};

UCLASS(Blueprintable)
class SKSIMULATORGAME_API UPointSystem : public UObject
{
	GENERATED_BODY()
public:
	UPointSystem();

	UPROPERTY(VisibleAnywhere)
	FPointsStruct PointsStruct;
	UPROPERTY(EditAnywhere)
	TMap<EPointsEvent, FPointEventStruct> PointsMap;

	UFUNCTION()
	virtual void OnEvent(EPointsEvent Event, float LocalMultiplier = 1.0f);

	UFUNCTION()
	virtual float GetScore() { return PointsStruct.GetScore(); }


};
