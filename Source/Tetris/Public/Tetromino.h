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

	UPROPERTY(EditAnywhere)
	int32 gridsize = 120;

	
	
};
