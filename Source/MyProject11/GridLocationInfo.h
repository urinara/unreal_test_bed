// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GridLocationInfo.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct MYPROJECT11_API FGridLocationInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString URL;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UFID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Attribute0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Attribute1;
};
