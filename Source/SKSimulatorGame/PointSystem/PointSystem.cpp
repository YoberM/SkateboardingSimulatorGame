#include "PointSystem.h"

UPointSystem::UPointSystem()
{
}

void UPointSystem::OnEvent(EPointsEvent Event, float LocalMultiplier)
{
	if (Event == EPointsEvent::None)
		return;
	FPointEventStruct* PointEvent = PointsMap.Find(Event);
	if (PointEvent)
	{
		PointsStruct.Score += PointEvent->PointsToAddToScore * LocalMultiplier * PointEvent->Multiplier;
	}
}
