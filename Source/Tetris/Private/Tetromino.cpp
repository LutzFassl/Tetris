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
	
}

// Called every frame
void ATetromino::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

}

bool ATetromino::MoveLeftIfPossible()
{	// TODO Introduce speed, atm not possible to hold arrow
	// TODO think if possible to use ONE method (value +- one, using axis mapping)
	FVector Translation = FVector(0, -gridsize, 0);
	FVector NewLocation = GetActorLocation() + Translation;
	
	if (ValidateNewLocationForEachCube(Translation))
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

bool ATetromino::MoveRightIfPossible()
{
	FVector Translation = FVector(0, gridsize, 0);
	FVector NewLocation = GetActorLocation() + Translation;
	
	if (ValidateNewLocationForEachCube(Translation))
	{
		SetActorLocation(NewLocation);
		return true;
	}
	else
	{
		return false;
	}
}

bool ATetromino::MoveDownIfPossible()
{
	FVector Translation = FVector(0, 0, -gridsize);
	FVector NewLocation = GetActorLocation() + Translation;

	if (ValidateNewLocationForEachCube(Translation))
	{
		SetActorLocation(NewLocation);
		return true;
	}
	else
	{
		return false;
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

		// Check for collision with other Tetrominos
		
		bool IsSurrounded = HasSurroundingTetrominos(CubeLocation);



		// TODO distinguish between 1) invalid new position due to side collision (acceptable) and 2) invalid new position due to bottom collision -> Depossess via GameManager

		// Check if will be out of Bounds, // TODO umbauen auf Linetracing / ray casting instead of Y / Z position comparing
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

//TODO eventuell ENum Right, Down, Left und die drei in eine Funktion packen
bool ATetromino::CubeCanGoRight(FVector CubeLocation)
{
	FVector RightOfCube = CubeLocation + FVector(0, gridsize, 0);
	auto HitResult = CheckForSurroundingBody(CubeLocation, RightOfCube);
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

bool ATetromino::CubeCanGoLeft(FVector CubeLocation)
{
	FVector LeftOfCube = CubeLocation + FVector(0, -gridsize, 0);
	auto HitResult = CheckForSurroundingBody(CubeLocation, LeftOfCube);
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

bool ATetromino::CubeCanGoDown(FVector CubeLocation)

	FVector BelowCube = CubeLocation + FVector(0, 0, -gridsize);
	auto HitResult = CheckForSurroundingBody(CubeLocation, BelowCube);
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


	//UE_LOG(LogTemp, Warning, TEXT("owner of Tetromino.Cpp = %s"), *GetOwner()->GetName());

	/////// Draw a red trace in the world to visualize
	//DrawDebugLine(
	//	GetWorld(),
	//	CubeLocation, //FVector(1500, 0, 100), //PlayerViewPointLocation,
	//	RightOfCube,
	//	FColor(255, 0, 255),
	//	true,
	//	0.5f,
	//	0.f,
	//	10.f);

	//DrawDebugLine(
	//	GetWorld(),
	//	CubeLocation, //FVector(1500, 0, 100), //PlayerViewPointLocation,
	//	CubeLocation + FVector(0, -gridsize, 0),
	//	FColor(255, 0, 255),
	//	true,
	//	0.5f,
	//	0.f,
	//	10.f);

	//DrawDebugLine(
	//	GetWorld(),
	//	CubeLocation, //FVector(1500, 0, 100), //PlayerViewPointLocation,
	//	CubeLocation + FVector(0, 0, -gridsize),
	//	FColor(255, 0, 255),
	//	true,
	//	0.5f,
	//	0.f,
	//	10.f);

	//GetWorld()->GetFirstPlayerController()->SetPause(true);

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

	///// See what we hit
	//AActor* ActorHit = HitResult.GetActor();
	//if (ActorHit)		// prevent errors
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("We have hit the: %s"), *ActorHit->GetName());
	//}

	return HitResult;
}

