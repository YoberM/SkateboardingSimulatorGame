#include "SKGameMode.h"

#include "SKSimulatorGame/PointSystem/PointSystem.h"

ASKGameMode::ASKGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASKGameMode::BeginPlay()
{
	Super::BeginPlay();
	if (PointSystemClass)
		PointSystem = NewObject<UPointSystem>(this,PointSystemClass);
}

void ASKGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	Totaltime += DeltaSeconds;
}

ASKGameMode* ASKGameMode::GetSKGameMode(UWorld* World)
{
	ASKGameMode* instance = Cast<ASKGameMode>(World->GetAuthGameMode());
	return instance;
}

void ASKGameMode::NotifyPointSystem(EPointsEvent PointsEvent, float ScoreMultiplier)
{
	if (PointSystem)
		PointSystem->OnEvent(PointsEvent, ScoreMultiplier);
}
