#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseObstacle.generated.h"

enum class EPointsEvent : uint8;

UCLASS()
class SKSIMULATORGAME_API ABaseObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseObstacle();
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualComponent {nullptr};
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyPointSystem();

	EPointsEvent PointsEventOnAttach { 0 };

};
