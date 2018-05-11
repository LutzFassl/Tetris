// Tetris by Lutz

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tetromino.generated.h"


UENUM()		//"BlueprintType" is essential to include
enum class EDirection : uint8
{
	Left,
	Right,
	Down,
};


UCLASS()
class TETRIS_API ATetromino : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATetromino();

	// Public for GameManager
	bool MoveIfPossible(EDirection Direction);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	// Default Routines
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	void MoveAtSensibleTickRate(EDirection Direction);
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Collision Functions
	bool CubeCanGoThisDirection(FVector CubeLocation, EDirection Direction);
	const FHitResult CheckForSurroundingBody(FVector CubeLocation, FVector SurroundLocation);
	bool IsPredictedLocationForEachCubeOK(EDirection Direction);

	UFUNCTION(BlueprintCallable)
	void RotateCW_IfPossible();

	// VARIABLES
	EDirection Direction;
	TArray<float> LastTimeMoved = { -1, -1, -1 }; // Remember when used last time to slow down the movement speed by user,  0 = left, 1 = right, 2 = down
	
	UPROPERTY(EditAnywhere)
	float UserMoveSpeed = 10;
	
	float MoveDelay=0.1;		//Inverted UserMoveSpeed will be calculated at BeginPlay because UserMoveSpeed is easier to comprehend

	//TODO delete and get from GameManager
	UPROPERTY(EditAnywhere)
	int32 gridsize = 120;

	// TODO DISREGARD, will not be necessary after ray trace solution with invisible walls, --> OLD, IGNORE: check Maybe read those from the gameBaseMode or GameManager
	UPROPERTY(EditAnywhere)
	int32 boundaryLeft = 0;

	UPROPERTY(EditAnywhere)
	int32 boundaryRight = 1196;

	UPROPERTY(EditAnywhere)
	int32 boundaryBottom = 0;
};


