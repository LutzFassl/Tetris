// Tetris by Lutz

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JustACube.generated.h"

UCLASS()
class TETRIS_API AJustACube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AJustACube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
