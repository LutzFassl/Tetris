// Tetris by Lutz

#include "Components/BoxComponent.h"
#include "TetrisCollisionBoxes.h"


// Sets default values
ATetrisCollisionBoxes::ATetrisCollisionBoxes()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATetrisCollisionBoxes::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATetrisCollisionBoxes::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UBoxComponent* MyTriggerVolume = FindComponentByClass<UBoxComponent>();
	if (MyTriggerVolume) 
	{
		TArray<AActor*> OverlappingActors;
		//UE_LOG(LogTemp, Warning, TEXT("Vol Name: %s"), *MyTriggerVolume->GetName());
		MyTriggerVolume->GetOverlappingActors(OUT OverlappingActors);

		for (const auto& i_actor : OverlappingActors)
		{
			UE_LOG(LogTemp, Warning, TEXT("Overlapping with: %s"), *i_actor->GetName());
			//UPrimitiveComponent* thiscomp =  no definition needed
			//TotalMass += i_actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();		// += addiert drauf
			//UE_LOG(LogTemp, Warning, TEXT("This is actor: %s"), **FString::SanitizeFloat(TotalMass));
		}
	}
	return;
}

