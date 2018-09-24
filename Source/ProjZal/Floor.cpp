// Fill out your copyright notice in the Description page of Project Settings.

#include "Floor.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"


// Sets default values
AFloor::AFloor()
{
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> RockMesh(TEXT("/Game/ThirdPerson/Meshes/CubeMesh.CubeMesh"));

	// Create the mesh component
	FloorMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ground"));
	RootComponent = FloorMeshComponent;
	FloorMeshComponent->SetWorldScale3D(FVector(1.0F, 1.0F, 0.2F));

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloor::BeginPlay()
{
	Super::BeginPlay();

	FloorMeshComponent->SetStaticMesh(RockMesh);
}

// Called every frame
void AFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

