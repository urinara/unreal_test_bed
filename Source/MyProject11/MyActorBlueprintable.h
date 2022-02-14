// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActorBlueprintable.generated.h"

UCLASS(Blueprintable)
class MYPROJECT11_API AMyActorBlueprintable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActorBlueprintable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

USTRUCT(Blueprintable, NotBlueprintType)
struct FMyStructable
{
	GENERATED_BODY()

public:
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Struct")
	//float GridX;
};

USTRUCT(BlueprintType)
struct FMyStructType
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Struct")
        float GridZ;
};
