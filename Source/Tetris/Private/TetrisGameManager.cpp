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
	int32 Tetromino_Type = FMath::RandRange(1, 7);
	UE_LOG(LogTemp, Warning, TEXT("This Tetromino will be Nr: %d"), Tetromino_Type);
	switch (Tetromino_Type)
	{
	case 1: ThisTetromino = GetWorld()->SpawnActor<ATetromino>(Tetromino_1, StartPosition, FRotator(0, 0, 0)); break;
	case 2: ThisTetromino = GetWorld()->SpawnActor<ATetromino>(Tetromino_2, StartPosition, FRotator(0, 0, 0)); break;
	case 3: ThisTetromino = GetWorld()->SpawnActor<ATetromino>(Tetromino_3, StartPosition, FRotator(0, 0, 0)); break;
	case 4: ThisTetromino = GetWorld()->SpawnActor<ATetromino>(Tetromino_4, StartPosition, FRotator(0, 0, 0)); break;
	case 5: ThisTetromino = GetWorld()->SpawnActor<ATetromino>(Tetromino_5, StartPosition, FRotator(0, 0, 0)); break;
	case 6: ThisTetromino = GetWorld()->SpawnActor<ATetromino>(Tetromino_6, StartPosition, FRotator(0, 0, 0)); break;
	case 7: ThisTetromino = GetWorld()->SpawnActor<ATetromino>(Tetromino_7, StartPosition, FRotator(0, 0, 0)); break;
	}
}

void UTetrisGameManager::SpawnNextTetromino()
{
	int32 Tetromino_Type = FMath::RandRange(1, 7);
	UE_LOG(LogTemp, Warning, TEXT("Next Tetromino will be Nr: %d"), Tetromino_Type);
	switch (Tetromino_Type)
	{
	case 1: NextTetromino = GetWorld()->SpawnActor<ATetromino>(Tetromino_1, PreviewPosition, FRotator(0, 0, 0)); break;
	case 2: NextTetromino = GetWorld()->SpawnActor<ATetromino>(Tetromino_2, PreviewPosition, FRotator(0, 0, 0)); break;
	case 3: NextTetromino = GetWorld()->SpawnActor<ATetromino>(Tetromino_3, PreviewPosition, FRotator(0, 0, 0)); break;
	case 4: NextTetromino = GetWorld()->SpawnActor<ATetromino>(Tetromino_4, PreviewPosition, FRotator(0, 0, 0)); break;
	case 5: NextTetromino = GetWorld()->SpawnActor<ATetromino>(Tetromino_5, PreviewPosition, FRotator(0, 0, 0)); break;
	case 6: NextTetromino = GetWorld()->SpawnActor<ATetromino>(Tetromino_6, PreviewPosition, FRotator(0, 0, 0)); break;
	case 7: NextTetromino = GetWorld()->SpawnActor<ATetromino>(Tetromino_7, PreviewPosition, FRotator(0, 0, 0)); break;
	}
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
		CurrentPawn = Cast<ATetromino>(TetrominoController->GetPawn());
		
		if (!ensure(TetrominoController) || (!ensure(CurrentPawn))) { return; }
		//UE_LOG(LogTemp, Warning, TEXT("ControllerName: %s, PawnName: %s"), *TetrominoController->GetName(), *CurrentPawn->GetName());
		//if (CurrentPawn->MoveDownIfPossible())
		//{

		//}
		//else
		//{
		//	TetrominoController->UnPossess();
		//	ThisTetromino = NextTetromino;
		//	ThisTetromino->SetActorLocation(StartPosition);
		//	SpawnNextTetromino();
		//	TetrominoController->Possess(ThisTetromino);
		//	
		//}
		lastInt = thisInt;
	}
}