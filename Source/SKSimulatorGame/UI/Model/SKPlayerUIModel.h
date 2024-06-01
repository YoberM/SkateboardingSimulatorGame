// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SKPlayerUIModel.generated.h"

class UTextBlock;


UCLASS()
class SKSIMULATORGAME_API USKPlayerUIModel : public UObject
{
	GENERATED_BODY()
public:
    USKPlayerUIModel();
    UPROPERTY(BlueprintReadWrite)
    float Score { 0.0f };
    
    UPROPERTY(BlueprintReadWrite)
    float Speed { 0.0f };

	UPROPERTY(BlueprintReadWrite)
    float TotalTime { 0 };
    
    float GetScore() const { return Score; }
    float GetSpeed() const { return Speed; }
    
    void SetScore(float NewScore);
    void SetSpeed(float NewSpeed);
    void SetTotalTime(float NewTotalTime);
    
};
