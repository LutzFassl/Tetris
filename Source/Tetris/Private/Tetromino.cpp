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
	// TODO think if possible to use ONE method (value +- one, using axis mapping)
	FVector Translation = FVector(0, -gridsize, 0);
	FVector NewLocation = GetActorLocation() + Translation;
	
	if (ValidateNewLocationForEachCube(Translation))
	{
		SetActorLocation(NewLocation);
	}
}

// TODO move only between frames? To fix blurry movement

void ATetromino::MoveRightIfPossible()
{
	FVector Translation = FVector(0, gridsize, 0);
	FVector NewLocation = GetActorLocation() + Translation;
	
	if (ValidateNewLocationForEachCube(Translation))
	{
		SetActorLocation(NewLocation);
	}
}

void ATetromino::MoveDownIfPossible()
{
	FVector Translation = FVector(0, 0, -gridsize);
	FVector NewLocation = GetActorLocation() + Translation;

	if (ValidateNewLocationForEachCube(Translation))
	{
		SetActorLocation(NewLocation);
	}
	
}

bool ATetromino::ValidateNewLocationForEachCube(FVector NewLocOfRootOfTetromino)
{
	bool NewPosIsOk = true;
	// Get Array of Cubes
	TArray<UStaticMeshComponent*> Cubes;
	GetComponents<UStaticMeshComponent>(Cubes);

	// Loop through cubes to check if new Location is within boundaries
	for (int y = 0; y < Cubes.Num(); y++)
	{
		UStaticMeshComponent* thisCube = Cast<UStaticMeshComponent>(Cubes[y]);
		FVector CubeLocation = thisCube->GetComponentLocation();
		FVector NewCubeLocation = CubeLocation + NewLocOfRootOfTetromino;
		//UE_LOG(LogTemp, Warning, TEXT("%dY = %f, %dZ = %f"), y, CubeLocation.Y, y, CubeLocation.Z);
		//UE_LOG(LogTemp, Warning, TEXT("Vector: %s"), *NewLocOfRootOfTetromino.ToString());

		if (NewCubeLocation.Y < boundaryLeft || NewCubeLocation.Y > boundaryRight) { NewPosIsOk = false; }
		if (NewCubeLocation.Z < boundaryBottom) { NewPosIsOk = false; }
		//UE_LOG(LogTemp, Warning, TEXT("NewY = %f, NewZ = %f"), *thisCube->GetName(), *MeshLocation.ToString());
		//UE_LOG(LogTemp, Warning, TEXT("NewY = %f, NewZ = %f"), NewCubeLocation.Y, NewCubeLocation.Z);
	}
	return NewPosIsOk;
}

void ATetromino::RotateCW_IfPossible()
{
	// push away from left/right boundary to perform rotation if too close to boundary, but only if not colliding with other tetromino
	// TODO think if possible to use ONE method (value +- one, using axis mapping)
	FRotator NewRotation = GetActorRotation() + FRotator(0, 0, 90);
	SetActorRotation(NewRotation);
}




// Called to bind functionality to input
void ATetromino::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

