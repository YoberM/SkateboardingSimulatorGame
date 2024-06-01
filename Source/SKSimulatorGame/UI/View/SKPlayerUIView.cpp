#include "SKPlayerUIView.h"

#include "Components/TextBlock.h"

void USKPlayerUIView::UpdateScore(float NewScore)
{
	ScoreTextBlock->SetText(FText::FromString(FString::SanitizeFloat(NewScore,2)));
}

void USKPlayerUIView::UpdateSpeed(float NewSpeed)
{
	SpeedTextBlock->SetText(FText::FromString(FString::SanitizeFloat(NewSpeed,2)));
}

void USKPlayerUIView::UpdateTotalTime(float NewTotalTime)
{
	int Minutes = StaticCast<int>(NewTotalTime) / 60;
	int Seconds = StaticCast<int>(NewTotalTime) % 60;
	FString TimeString = FString::Printf(TEXT("%02d:%02d"), Minutes, Seconds);
	TotalTimeTextBlock->SetText(FText::FromString(TimeString));
}

void USKPlayerUIView::NativeConstruct()
{
	Super::NativeConstruct();
}
