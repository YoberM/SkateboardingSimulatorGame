#pragma once

#include "CoreMinimal.h"
#include "SKPlayerUIController.generated.h"

class USKPlayerUIView;
class USKPlayerUIModel;

UCLASS(Blueprintable)
class SKSIMULATORGAME_API USKPlayerUIController : public UObject
{
	GENERATED_BODY()
public:
    virtual void Initialize(APlayerController* PlayerController);

    UFUNCTION(BlueprintCallable)
    void UpdateScore(float NewScore);
    
    UFUNCTION(BlueprintCallable)
    void UpdateSpeed(float NewSpeed);

    UFUNCTION(BlueprintCallable)
    void UpdateTotalTime(float NewTotalTime);

    UFUNCTION(BlueprintCallable)
    USKPlayerUIModel* GetPlayerModel() const { return PlayerModel; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = UI)
	TSubclassOf<USKPlayerUIView> PlayerUIClass {nullptr};
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = UI)
    USKPlayerUIView* PlayerView {nullptr};
    UPROPERTY()
    USKPlayerUIModel* PlayerModel {nullptr};

};
