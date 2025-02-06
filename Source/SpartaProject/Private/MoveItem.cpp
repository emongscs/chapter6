// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveItem.h"

// Sets default values
AMoveItem::AMoveItem()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;



}

// Called when the game starts or when spawned
void AMoveItem::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	MoveDirection = 1.0f;
	
}

// Called every frame
void AMoveItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	FVector NextLocation = CurrentLocation + FVector(MoveSpeed * MoveDirection * DeltaTime, 0.f, 0.f);

	float DistanceMoved = FVector::Dist(StartLocation, NextLocation);

	// �ִ� ������ ����� �̵� ���� ����
	if (DistanceMoved >= MaxRange)
	{
		MoveDirection *= -1.0f; // ���� ����
		NextLocation = CurrentLocation + FVector(MoveSpeed * MoveDirection * DeltaTime, 0.f, 0.f); // ���� �� �̵�
	}

	SetActorLocation(NextLocation);

}

