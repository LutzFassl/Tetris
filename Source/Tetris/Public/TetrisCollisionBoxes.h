// Tetris by Lutz

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TetrisCollisionBoxes.generated.h"

class UBoxComponent;

UCLASS()
class TETRIS_API ATetrisCollisionBoxes : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATetrisCollisionBoxes();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void FindAllCubesAboveAndMoveThemDown(float Z_ThisRow);

	int32 gridsize = 120;

	
	
};
