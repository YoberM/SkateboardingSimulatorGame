#include "SKGameMode.h"

ASKGameMode::ASKGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
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
