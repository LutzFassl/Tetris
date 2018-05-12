// Tetris by Lutz

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tetromino.generated.h"

class AJustACube;


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
	void Disassemble();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	// Routines
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
	
	// Pointers
	TArray<UStaticMeshComponent*> Cubes;	//own cubes before disassembly
	TArray<AJustACube*> ReplacingCubes = { nullptr,nullptr,nullptr,nullptr };		// or AActor
	
	UPROPERTY(EditAnywhere)
	float UserMoveSpeed = 10;
	
	float MoveDelay=0.1;		//Inverted UserMoveSpeed will be calculated at BeginPlay because UserMoveSpeed is easier to comprehend

	//TODO delete and get from GameManager
	UPROPERTY(EditAnywhere)
	int32 gridsize = 120;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AJustACube> CubeType;
	//TSubclassOf<UStaticMeshComponent> CubeType;
};


