// Tetris by Lutz

#include "../public/Tetromino.h"


// Sets default values
ATetromino::ATetromino()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATetromino::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATetromino::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATetromino::MoveLeftIfPossible()
{	// TODO Introduce speed, atm not possible to hold arrow
	// TODO stopmovement if will get out of bounds
	// TODO think if possible to use ONE method (value +- one, using axis mapping)
	FVector NewLocation = GetActorLocation() + FVector(0, -gridsize, 0);
	if (NewLocation.Y > boundaryLeft)
	{
		SetActorLocation(NewLocation);
	}
	
}

// TODO move only between frames? To fix blurry movement

void ATetromino::MoveRightIfPossible()
{
	FVector NewLocation = GetActorLocation() + FVector(0, gridsize, 0);
	if (NewLocation.Y < boundaryRight)
	{
		SetActorLocation(NewLocation);
	}
}

void ATetromino::MoveDownIfPossible()
{
	FVector NewLocation = GetActorLocation() + FVector(0, 0, -gridsize);

	if (NewLocation.Z > boundaryBottom)
	{
		SetActorLocation(NewLocation);
	}
}

void ATetromino::RotateCW_IfPossible()
{
	// TODO stopmovement if will get out of bounds
	// TODO think if possible to use ONE method (value +- one, using axis mapping)
	// collision control
	FRotator NewRotation = GetActorRotation() + FRotator(0, 0, 90);
	SetActorRotation(NewRotation);
}




// Called to bind functionality to input
void ATetromino::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

