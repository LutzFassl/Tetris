// Tetris by Lutz

#include "../public/TetrisGameManager.h"
#include "../public/Tetromino.h"


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
}


// Called every frame
void UTetrisGameManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Create & Calculate Integers for custom (slowed) ticking
	float Time = GetWorld()->GetTimeSeconds();
	int32 thisInt = FMath::DivideAndRoundDown(Time, interval);
	//UE_LOG(LogTemp, Warning, TEXT("lastInt: %d, thisInt: %d"), lastInt, thisInt);

	//Actual Tick
	if (thisInt > lastInt)
	{
		// TODO possessed pawn can be find only on PossessedPawnChange and dont need to be checked every tick
		TetrominoController = GetWorld()->GetFirstPlayerController();
		CurrentPawn = Cast<ATetromino>(TetrominoController->GetPawn());
		

		if (!ensure(TetrominoController) || (!ensure(CurrentPawn))) { return; }
		//UE_LOG(LogTemp, Warning, TEXT("ControllerName: %s, PawnName: %s"), *TetrominoController->GetName(), *CurrentPawn->GetName());
		if (CurrentPawn->MoveDownIfPossible())
		{

		}
		else
		{
			TetrominoController->UnPossess();
		}
		lastInt = thisInt;
	}
}