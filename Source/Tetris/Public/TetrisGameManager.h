// Tetris by Lutz

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "TetrisGameManager.generated.h"


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
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void MovePawnDownIfPossible();

	UPROPERTY(EditAnywhere)
	float interval = 1.f;

	// To calculate custom "tick" or "interval" within tick every frame
	int32 lastInt = 0;

	APlayerController* TetrominoController = nullptr;
	APawn* CurrentPawn = nullptr;

		
	
};
