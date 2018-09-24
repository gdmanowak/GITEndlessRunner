// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ProjZalCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

//////////////////////////////////////////////////////////////////////////
// AProjZalCharacter

AProjZalCharacter::AProjZalCharacter()
{
	bool life = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;


	GetCharacterMovement()->MaxWalkSpeed = 200.0F;

	

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 54.0f));
	SpringArm->SetWorldRotation(FRotator(-20.0f, 0.0f, 0.0f));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 525.0f;
	SpringArm->bEnableCameraLag = false;
	SpringArm->bEnableCameraRotationLag = false;
	SpringArm->bInheritPitch = true;
	SpringArm->bInheritYaw = true;
	SpringArm->bInheritRoll = true;

	//tymczasowo
	// Create the chase camera component 
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ChaseCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->SetRelativeRotation(FRotator(10.0f, 0.0f, 0.0f));
	Camera->bUsePawnControlRotation = false;
	Camera->FieldOfView = 90.f;

	//end new

	// new 12

	//new 2
	direction = 0;//direction player is facing (values 0 to 3)
	canTurnRight = true;//used to prevent the player turning more than 90 degrees on a single key press
						//end new 2

						//new 4
	floorDirection = FVector(1, 0, 0);//Start in the positive x direction
	floorPosition = FVector(2000, 0, 0);//initial floor position
	frameCount = 0;//use to count number of frames since last floor piece was created - see Tick() function below
				   //end new 4

				   //new
	//end new 12

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void AProjZalCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	//PlayerInputComponent->BindAxis("MoveForward", this, &AProjZalCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AProjZalCharacter::ChangeDirection);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AProjZalCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AProjZalCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AProjZalCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AProjZalCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AProjZalCharacter::OnResetVR);
}


void AProjZalCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AProjZalCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void AProjZalCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void AProjZalCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AProjZalCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AProjZalCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AProjZalCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

//new 3
void AProjZalCharacter::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	if (direction == 0)
		MoveForward(1);
	else if (direction == 2)
		MoveForward(-1);
	else if (direction == 1)
		MoveRight(1);
	else if (direction == 3)
		MoveRight(-1);

	//new 4
	AFloor *myFloor;

	// tymczasowo zeby uruchomic projekt
	UWorld* const World = GetWorld();
	if (World && frameCount++ > 15) {
		frameCount = 0;
		FVector SpawnLocation = floorPosition;// GetActorLocation() + FVector(0, newCount * 100, -5);
		floorPosition += floorDirection * 400;
		updateFloorDirection(floorDirection);
		const FRotator FloorRotation = FRotator(0, 0, 0);
		myFloor = World->SpawnActor<AFloor>(ClassToSpawn, SpawnLocation, FloorRotation);
	}
	//end new 4
}
//end new 3

void AProjZalCharacter::ChangeDirection(float Value)
{
	if (Value != 0 && canTurnRight) {
		canTurnRight = false;
		direction += Value;
		if (direction > 3)
			direction = 0;
		else if (direction < 0)
			direction = 3;
	}
	else if (Value == 0)
		canTurnRight = true;
}
//end new 2

//new 4
void AProjZalCharacter::updateFloorDirection(FVector& direction) {

	float zChange = 0.0F;//used to randomly change the height of the floor piece

	int randNum1 = rand() % 15;
	int randNum2 = rand() % 10;
	if (randNum2 > 7)
		zChange = 0;
	else if (randNum2 > 4)
		zChange = 0;

	switch (randNum1) {

	case 4:
		if (floorDirection.X != -1)
			floorDirection = FVector(1, 0, zChange);
		break;
	case 12:
		if (floorDirection.Y != 1)
			floorDirection = FVector(0, -1, zChange);
		break;
	case 8:
		//newCount = 0;
		if (floorDirection.X != 1)
			floorDirection = FVector(-1, 0, zChange);
		break;
	case 0:
		if (floorDirection.Y != -1)
			floorDirection = FVector(0, 1, zChange);
		break;
	}

}
//end new 4