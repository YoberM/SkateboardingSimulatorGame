#include "SKAttachableObstacle.h"

#include "Components/SplineComponent.h"
#include "SKSimulatorGame/Character/SKCharacter.h"

ASKAttachableObstacle::ASKAttachableObstacle()
{
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
	if (ASKCharacter* Character = Cast<ASKCharacter>(OtherActor))
	{
		AttachCharacterToObstacle(Character);
	}

}

void ASKAttachableObstacle::AttachCharacterToObstacle(ASKCharacter* CharacterToAttach)
{
	bIsActorAttached = true;
	SKCharacter = CharacterToAttach;
	InitialVelocity = SKCharacter->GetVelocity().Size2D();
}

void ASKAttachableObstacle::HandleActorOnAttach(float DeltaTime)
{
    if (SplineComponent)
    {
        DistanceAlongSpline += DeltaTime * VelocityFactor * InitialVelocity; // Adjust speed as needed
        SKCharacter->SetActorLocation(SplineComponent->GetLocationAtDistanceAlongSpline(DistanceAlongSpline, ESplineCoordinateSpace::World));
		if ( SplineComponent->GetSplineLength() < DistanceAlongSpline )
		{
			bIsActorAttached = false;
			SKCharacter = nullptr;
			DistanceAlongSpline = 0.0f;
		}
    }
}
