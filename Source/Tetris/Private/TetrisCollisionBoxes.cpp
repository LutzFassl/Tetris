// Tetris by Lutz

#include "../Public/TetrisCollisionBoxes.h"
#include "../Public/JustACube.h"
#include "EngineUtils.h"
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
	TArray<UActorComponent*> BoxArray = GetComponentsByClass(UBoxComponent::StaticClass());
	TArray<AActor*> OverlappingActors;
	UBoxComponent* thisbox;
	int32 OverlappingCubeCounter;

	// Loop through all Collision Boxes
	for (int32 i = 0; i < BoxArray.Num(); i++)
	{
		//UE_LOG(LogTemp, Warning, TEXT("I am Box: %s"), *BoxArray[i]->GetName());


		// TODO start to loop through them from top row to bottom
		// Pointer Protection
		if (BoxArray[i])
		{
			OverlappingCubeCounter = 0;
			OverlappingActors.Empty();											// clear overlapping array
			thisbox = Cast<UBoxComponent>(BoxArray[i]);
			thisbox->GetOverlappingActors(OUT OverlappingActors);		// fill overlapping actor array
			if (OverlappingActors.Num() == 10)
			{
				//UE_LOG(LogTemp, Warning, TEXT("%s has overlapping Actors: %d"), *BoxArray[i]->GetName(), OverlappingActors.Num());
						// Loop through overlapping actors
						for (const auto& i_actor : OverlappingActors)
						{
							// disregard all Actors that are not JustACube
							if (i_actor->IsA(AJustACube::StaticClass())) 
							{
								OverlappingCubeCounter++;
								//UE_LOG(LogTemp, Warning, TEXT("Overlapping with: %s"), *i_actor->GetName());
							}
						}

						// if 10 Cubes then delete them and move all cubes above one row down
						if (OverlappingCubeCounter == 10)
						{
							for (const auto& i_actor : OverlappingActors)
							{
								if (i_actor->IsA(AJustACube::StaticClass()))
								{
									i_actor->Destroy();
								}
							}
							FindAllCubesAboveAndMoveThemDown(0);	//TODO correct Z value
						}
			}
		}
	}

	
	////UBoxComponent* MyTriggerVolume = FindComponentByClass<UBoxComponent>();		// Specify which of the 20 correct boxes. Man könnte alternativ die auch einfach nach höhe sortieren
	//if (MyTriggerVolume) 
	//{
	//	TArray<AActor*> OverlappingActors;
	//	//UE_LOG(LogTemp, Warning, TEXT("Vol Name: %s"), *MyTriggerVolume->GetName());
	//	MyTriggerVolume->GetOverlappingActors(OUT OverlappingActors);

	//	
	//	UE_LOG(LogTemp, Warning, TEXT("Amount of Elements: %d"), OverlappingActors.Num());

	//	// Destroy all. Should probably be done by GameManager
	//	if (OverlappingActors.Num() == 10)
	//	{
	//		for (const auto& i_actor : OverlappingActors)
	//		{
	//			i_actor->Destroy();
	//			//UE_LOG(LogTemp, Warning, TEXT("Overlapping with: %s"), *i_actor->GetName());
	//			//UPrimitiveComponent* thiscomp =  no definition needed
	//			//TotalMass += i_actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();		// += addiert drauf
	//			//UE_LOG(LogTemp, Warning, TEXT("This is actor: %s"), **FString::SanitizeFloat(TotalMass));
	//		}

	//		// TODO set sensible Z value (e.g. 50 above own collision mesh pos)
	//		FindAllCubesAboveAndMoveThemDown(0.f);
	//	}
	//}
	return;
}

void ATetrisCollisionBoxes::FindAllCubesAboveAndMoveThemDown(float Z_ThisRow)
{
	for (TActorIterator<AJustACube> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		// TODO only if above Z pos
		FVector Translation = FVector(0, 0, -gridsize);
		FVector NewLocation = ActorItr->GetActorLocation() + Translation;
		ActorItr->SetActorLocation(NewLocation);
	}
}

