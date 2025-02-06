// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveItem.generated.h"

UCLASS()
class SPARTAPROJECT_API AMoveItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AMoveItem();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components") // 아랫줄 변수가 리플렉션 적용됨.
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MoveSpeed = 200.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MaxRange = 500.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	FVector StartLocation;
	UPROPERTY(VisibleAnywhere, Category = "Movement")
	float MoveDirection;



protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


};
