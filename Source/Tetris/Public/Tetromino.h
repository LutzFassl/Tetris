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

	UFUNCTION(BlueprintCallable)
	void MoveDownIfPossible();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

private:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void MoveLeftIfPossible();

	UFUNCTION(BlueprintCallable)
	void MoveRightIfPossible();
	
	//Function exists twice here and in GameManager. To make better?
	

	UFUNCTION(BlueprintCallable)
	void RotateCW_IfPossible();

	//TODO delete and get from GameManager
	UPROPERTY(EditAnywhere)
	int32 gridsize = 120;

	// TODO Maybe read those from the gameBaseMode or GameManager
	UPROPERTY(EditAnywhere)
	int32 boundaryLeft = 0;

	UPROPERTY(EditAnywhere)
	int32 boundaryRight = 1196;

	UPROPERTY(EditAnywhere)
	int32 boundaryBottom = 0;

	bool ValidateNewLocationForEachCube(FVector RootOfTetromino);
	
	
};


