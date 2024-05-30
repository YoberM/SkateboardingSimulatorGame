#pragma once

#include "CoreMinimal.h"
#include "BaseObstacle.h"
#include "SKAttachableObstacle.generated.h"

class USplineComponent;
class ASKCharacter;
class UStaticMeshComponent;

UCLASS()
class SKSIMULATORGAME_API ASKAttachableObstacle : public ABaseObstacle
{
	GENERATED_BODY()
	ASKAttachableObstacle();
public:
	UPROPERTY(VisibleAnywhere)
	AActor* SKCharacter {nullptr};
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* AttachableMesh {nullptr};
	UPROPERTY(EditAnywhere)
    USplineComponent* SplineComponent {nullptr};
	UPROPERTY(EditAnywhere)
    bool bIsActorAttached {false};
	UPROPERTY(EditAnywhere)
    float DistanceAlongSpline {0.0f};
	UPROPERTY(EditAnywhere)
    float VelocityFactor { 5.0f };
	UPROPERTY(EditAnywhere)
    float InitialVelocity { 1.0f };
private:
	UFUNCTION()
	virtual void BeginPlay() override;
	UFUNCTION()
	virtual void OnConstruction(const FTransform& Transform) override;
	UFUNCTION()
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void AttachCharacterToObstacle(ASKCharacter* CharacterToAttach);
	UFUNCTION()
	virtual void HandleActorOnAttach(float DeltaTime);
};
