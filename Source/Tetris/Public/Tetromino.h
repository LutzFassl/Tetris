// Tetris by Lutz

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tetromino.generated.h"

UCLASS()
class TETRIS_API ATetromino : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATetromino();

	// Public for GameManager
	UFUNCTION(BlueprintCallable)
	bool MoveDownIfPossible();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	// Default Routines
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Collision Functions
	bool CubeCanGoRight(FVector CubeLocation);
	bool CubeCanGoLeft(FVector CubeLocation);
	bool CubeCanGoDown(FVector CubeLocation);
	const FHitResult CheckForSurroundingBody(FVector CubeLocation, FVector SurroundLocation);
	bool ValidateNewLocationForEachCube(FVector RootOfTetromino);

	// BP Callables so Input Keys can access directly
	UFUNCTION(BlueprintCallable)
	bool MoveLeftIfPossible();

	UFUNCTION(BlueprintCallable)
	bool MoveRightIfPossible();

	UFUNCTION(BlueprintCallable)
	void RotateCW_IfPossible();


	// VARIABLES
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


