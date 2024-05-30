#include "BaseObstacle.h"

ABaseObstacle::ABaseObstacle()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABaseObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

