// Tetris by Lutz

#include "../public/Tetromino.h"
#include "DrawDebugHelpers.h"


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
	MoveDelay = 1 / UserMoveSpeed;
	
}

// Called every frame
void ATetromino::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATetromino::MoveAtSensibleTickRate(EDirection Direction)
{
	int32 arrayPos;

	// Convert ENum to Array Position
	if (Direction == EDirection::Left) { arrayPos = 0; }
	if (Direction == EDirection::Right) { arrayPos = 1; }
	if (Direction == EDirection::Down) { arrayPos = 2; }

	// Apply time Penalty of next movement to reduce speed
	if (GetWorld()->GetTimeSeconds() - LastTimeMoved[arrayPos] > MoveDelay)
	{
		MoveIfPossible(Direction);
		LastTimeMoved[arrayPos] = GetWorld()->GetTimeSeconds();
	}
	return;
}

bool ATetromino::MoveIfPossible(EDirection Direction)
{
	FVector Translation;

	// Choose correct target vector
	switch (Direction)
	{
	case EDirection::Left: Translation = FVector(0, -gridsize, 0); break;
	case EDirection::Right: Translation = FVector(0, gridsize, 0); break;
	case EDirection::Down: Translation = FVector(0, 0, -gridsize); break;
	}
	
	FVector NewLocation = GetActorLocation() + Translation;
	
	if (IsPredictedLocationForEachCubeOK(Direction))
	{
		SetActorLocation(NewLocation);
		return true;
	}
	else
	{
		return false;
	}
}
// TODO move only between frames? To fix blurry movement

bool ATetromino::IsPredictedLocationForEachCubeOK(EDirection Direction)
{
	// Get Array of Cubes
	TArray<UStaticMeshComponent*> Cubes;
	GetComponents<UStaticMeshComponent>(Cubes);

	// Loop through cubes to check if new Location is within boundaries
	for (int y = 0; y < Cubes.Num(); y++)
	{
		UStaticMeshComponent* thisCube = Cast<UStaticMeshComponent>(Cubes[y]);
		FVector CubeLocation = thisCube->GetComponentLocation();
		if (!CubeCanGoThisDirection(CubeLocation, Direction)) { return false; }
		// TODO distinguish between 1) invalid new position due to side collision (acceptable) and 2) invalid new position due to bottom collision -> Depossess via GameManager
	}
	return true; //return true if not found any false in the 4-fold loop
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

//TODO eventuell ENum Right, Down, Left und die drei in eine Funktion packen
bool ATetromino::CubeCanGoThisDirection(FVector CubeLocation, EDirection Direction)
{
	// Define Target Vectors
	FVector LeftOfCube = CubeLocation + FVector(0, -gridsize, 0); 
	FVector RightOfCube = CubeLocation + FVector(0, gridsize, 0); 
	FVector BelowCube = CubeLocation + FVector(0, 0, -gridsize); 
	FVector TargetLocation;

	// Choose correct target vector
	switch (Direction)
	{
	case EDirection::Left: TargetLocation = LeftOfCube; break;
	case EDirection::Right: TargetLocation = RightOfCube; break;
	case EDirection::Down: TargetLocation = BelowCube; break;
	}

	// Line-Trace
	auto HitResult = CheckForSurroundingBody(CubeLocation, TargetLocation);
	auto ComponentHit = HitResult.GetComponent();
	auto ActorHit = HitResult.GetActor();

	if (ActorHit)
	{
		return false;
	}
	else
	{
		return true;
	}
}

const FHitResult ATetromino::CheckForSurroundingBody(FVector CubeLocation, FVector SurroundLocation)
{
	///// Setup query parameters
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, this);	 // rference to self possible? how? or by default ignores self?	// change false to true if want to check with complex model of objects, ignore ourselves because beam starts from center of pawn and would hit our pawn first if not ignored

	//																				/// Line-Trace Ray-cast out to reach distance
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByObjectType(
		OUT HitResult,
		CubeLocation,
		SurroundLocation,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);

	return HitResult;
}

