#include "SKPlayerUIModel.h"

USKPlayerUIModel::USKPlayerUIModel()
{

}

void USKPlayerUIModel::SetScore(float NewScore)
{
	Score = NewScore;
}

void USKPlayerUIModel::SetSpeed(float NewSpeed)
{
	Speed = NewSpeed;
}

void USKPlayerUIModel::SetTotalTime(float NewTotalTime)
{
	TotalTime = NewTotalTime;
}

