#include "SKAttachableObstacle.h"

#include "Components/SplineComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "SKSimulatorGame/Character/SKCharacter.h"

ASKAttachableObstacle::ASKAttachableObstacle()
{
	VisualComponent->SetupAttachment(RootComponent);

	AttachableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AttachableMesh"));
	AttachableMesh->SetupAttachment(RootComponent);
	AttachableMesh->SetMobility(EComponentMobility::Static);

	AttachableMesh->OnComponentBeginOverlap.AddDynamic(this,&ASKAttachableObstacle::OnOverlapBegin);

	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	SplineComponent->SetupAttachment(RootComponent);

}

void ASKAttachableObstacle::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	SplineComponent->SetWorldLocation(GetActorLocation());
}

void ASKAttachableObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bIsActorAttached)
	{
		HandleActorOnAttach(DeltaTime);
	}
}

void ASKAttachableObstacle::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ASKCharacter* Character = Cast<ASKCharacter>(OtherActor); 
		Character && 
		Character->ReattachmentDelayDT <= 0 &&
		!bIsActorAttached)
	{
		AttachCharacterToObstacle(Character);
	}

}

void ASKAttachableObstacle::AttachCharacterToObstacle(ASKCharacter* CharacterToAttach)
{
	if (CharacterToAttach->GetMovementComponent()->IsFalling())
	{
		bIsActorAttached = true;
		SKCharacter = CharacterToAttach;
		InitialVelocity = SKCharacter->GetVelocity();
		SKCharacter->SetAttachToObstacle(this);
	}
}

void ASKAttachableObstacle::HandleActorOnAttach(float DeltaTime)
{
    if (SplineComponent)
    {
        DistanceAlongSpline += DeltaTime * VelocityFactor * InitialVelocity.Size(); // Adjust speed as needed
		FVector NewLocation = SplineComponent->GetLocationAtDistanceAlongSpline(DistanceAlongSpline, ESplineCoordinateSpace::World);
		NewLocation += FVector(0.0f, 0.0f, SKCharacter->GetDefaultHalfHeight());
    	SKCharacter->SetActorLocation(NewLocation);
		FRotator NewRotation = SplineComponent->GetRotationAtDistanceAlongSpline(DistanceAlongSpline, ESplineCoordinateSpace::World);
		NewRotation.Pitch = 0.0f;
		NewRotation.Roll = 0.0f;
		SKCharacter->SetActorRotation(NewRotation);
    	if (SplineComponent->GetSplineLength() < DistanceAlongSpline)
		{
			UnAttachActor(DeltaTime);
		}
    }
}

void ASKAttachableObstacle::UnAttachActor(float DeltaTime)
{
	bIsActorAttached = false;
	SKCharacter->GetMovementComponent()->AddInputVector(SKCharacter->GetActorForwardVector()*InitialVelocity.Size2D());
	SKCharacter->SetAttachToObstacle(nullptr);
	SKCharacter = nullptr;
	DistanceAlongSpline = 0.0f;
}
