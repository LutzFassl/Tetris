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
	
	TetrominoController = GetWorld()->GetFirstPlayerController();

	// Setup First Tetromino
	SpawnThisTetromino();
	TetrominoController->Possess(ThisTetromino);
	
	
	// Setup next Tetromino
	SpawnNextTetromino();
}

void UTetrisGameManager::SpawnThisTetromino()
{
	if (Tetrominos.Num() > 0)
	{
		int32 RandomIndex = FMath::RandRange(0, Tetrominos.Num() - 1);
		ThisTetromino = GetWorld()->SpawnActor<ATetromino>(Tetrominos[RandomIndex], StartPosition, FRotator(0, 0, 0));
	}
}

void UTetrisGameManager::SpawnNextTetromino()
{
	if (Tetrominos.Num() > 0)
	{
		int32 RandomIndex = FMath::RandRange(0, Tetrominos.Num() - 1);
		NextTetromino = GetWorld()->SpawnActor<ATetromino>(Tetrominos[RandomIndex], PreviewPosition, FRotator(0, 0, 0));
	}
}


// Called every frame
void UTetrisGameManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//UE_LOG(LogTemp, Warning, TEXT("I'm the triggervolume: %s"), *TriggerVolumes[0]->GetName());
	

	// Create & Calculate Integers for custom (slowed) ticking
	float Time = GetWorld()->GetTimeSeconds();
	int32 thisInt = FMath::DivideAndRoundDown(Time, interval);
	

	//Actual Tick
	if (thisInt > lastInt)
	{
		// TODO possessed pawn can be find only on PossessedPawnChange and dont need to be checked every tick
		CurrentPawn = Cast<ATetromino>(TetrominoController->GetPawn());
		
		if (!ensure(TetrominoController) || (!ensure(CurrentPawn))) { return; }
		//UE_LOG(LogTemp, Warning, TEXT("ControllerName: %s, PawnName: %s"), *TetrominoController->GetName(), *CurrentPawn->GetName());
		if (CurrentPawn->MoveIfPossible(EDirection::Down))
		{
			// empty, is moved already in the condition
		}
		else
		{
			MoveOnToNextTetromino();
		}
		lastInt = thisInt;
	}
}

void UTetrisGameManager::MoveOnToNextTetromino()
{
	TetrominoController->UnPossess();
	ThisTetromino = NextTetromino;
	ThisTetromino->SetActorLocation(StartPosition);
	SpawnNextTetromino();
	TetrominoController->Possess(ThisTetromino);
}
