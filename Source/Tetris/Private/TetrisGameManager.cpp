// Tetris by Lutz

#include "TetrisGameManager.h"


// Sets default values for this component's properties
UTetrisGameManager::UTetrisGameManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTetrisGameManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTetrisGameManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("I got called."));


}

