#include "BaseObstacle.h"

ABaseObstacle::ABaseObstacle()
{
	VisualComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualComponent"));
	VisualComponent->SetupAttachment(RootComponent);

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

