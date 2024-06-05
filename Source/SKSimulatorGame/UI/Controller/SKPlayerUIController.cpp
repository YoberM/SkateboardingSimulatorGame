#include "SKPlayerUIController.h"
#include "SKSimulatorGame/UI/Model/SKPlayerUIModel.h"
#include "SKSimulatorGame/UI/View/SKPlayerUIView.h"

void USKPlayerUIController::Initialize(APlayerController* PlayerController)
{
	// Initializing model
	PlayerModel = NewObject<USKPlayerUIModel>();
	// Initializing viewport
	PlayerView = CreateWidget<USKPlayerUIView>(PlayerController, PlayerUIClass);
	if (PlayerView)
	{
		PlayerView->AddToViewport();
	}
}

void USKPlayerUIController::UpdateScore(float NewScore)
{
	if (PlayerModel)
	{
		PlayerModel->SetScore(NewScore);
		if (PlayerView)
		{
			PlayerView->UpdateScore(NewScore);
		}
	}
}

void USKPlayerUIController::UpdateSpeed(float NewSpeed)
{
	if (PlayerModel)
	{
		PlayerModel->SetSpeed(NewSpeed);
		if (PlayerView)
		{
			PlayerView->UpdateSpeed(NewSpeed);
		}
	}
}

void USKPlayerUIController::UpdateTotalTime(float NewTotalTime)
{
	if (PlayerModel)
	{
		PlayerModel->SetTotalTime(NewTotalTime);
		if (PlayerView)
		{
			PlayerView->UpdateTotalTime(NewTotalTime);
		}
	}
}
