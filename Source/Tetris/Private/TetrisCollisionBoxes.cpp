// Tetris by Lutz

#include "TetrisCollisionBoxes.h"
#include "Components/BoxComponent.h"



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
	UBoxComponent* MyTriggerVolume = FindComponentByClass<UBoxComponent>();		// Specify which of the 20 correct boxes. Man könnte alternativ die auch einfach nach höhe sortieren
	if (MyTriggerVolume) 
	{
		TArray<AActor*> OverlappingActors;
		//UE_LOG(LogTemp, Warning, TEXT("Vol Name: %s"), *MyTriggerVolume->GetName());
		MyTriggerVolume->GetOverlappingActors(OUT OverlappingActors);

		
		UE_LOG(LogTemp, Warning, TEXT("Amount of Elements: %d"), OverlappingActors.Num());

		// Destroy all. Should probably be done by GameManager
		if (OverlappingActors.Num() == 10)
		{
			for (const auto& i_actor : OverlappingActors)
			{
				i_actor->Destroy();

				// Move all components one row down TODO: should only be all components above it! z.B. Move all overlapping actors if z value is more than 50 more than current ro

				//UE_LOG(LogTemp, Warning, TEXT("Overlapping with: %s"), *i_actor->GetName());
				//UPrimitiveComponent* thiscomp =  no definition needed
				//TotalMass += i_actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();		// += addiert drauf
				//UE_LOG(LogTemp, Warning, TEXT("This is actor: %s"), **FString::SanitizeFloat(TotalMass));
			}
		}
	}
	return;
}

