// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SKPlayerUIView.generated.h"

class UTextBlock;

UCLASS()
class SKSIMULATORGAME_API USKPlayerUIView : public UUserWidget
{
	GENERATED_BODY()
public:
    UPROPERTY(meta = (BindWidget))
    UTextBlock* ScoreTextBlock;
    
    UPROPERTY(meta = (BindWidget))
    UTextBlock* SpeedTextBlock;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* TotalTimeTextBlock;
    
    UFUNCTION(BlueprintCallable)
    void UpdateScore(float NewScore);
    UFUNCTION(BlueprintCallable)
    void UpdateSpeed(float NewSpeed);
    UFUNCTION(BlueprintCallable)
	void UpdateTotalTime(float NewTotalTime);

protected:
    virtual void NativeConstruct() override;
};
