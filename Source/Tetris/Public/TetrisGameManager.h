// Tetris by Lutz

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "TetrisGameManager.generated.h"

class ATetromino;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TETRIS_API UTetrisGameManager : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTetrisGameManager();

	UPROPERTY(EditAnywhere)
	int32 gridsize = 120;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	

	

private:	
	// FUNCTIONS
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void SpawnThisTetromino();
	void SpawnNextTetromino();

	// POINTERS
	APlayerController* TetrominoController = nullptr;
	ATetromino* CurrentPawn = nullptr;
	ATetromino* NextTetromino = nullptr;
	ATetromino* ThisTetromino = nullptr;

	// VARIABLES
	UPROPERTY(EditAnywhere)
	float interval = 0.5f;

	// To calculate custom "tick" or "interval" within tick every frame
	int32 lastInt = 0;

	FVector StartPosition = FVector(1730, 538, 2218);
	FVector PreviewPosition = FVector (1730, 1700, 1738);

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<ATetromino> Tetromino_1;
	
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<ATetromino> Tetromino_2;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<ATetromino> Tetromino_3;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<ATetromino> Tetromino_4;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<ATetromino> Tetromino_5;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<ATetromino> Tetromino_6;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<ATetromino> Tetromino_7;
};
