// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Math/Vector.h"
#include "GridLocationInfo.h"
#include "RunTime/Online/HTTP/Public/HttpModule.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT11_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AMyPlayerController();

    UFUNCTION(BlueprintCallable, Category = "GIS")
    void ReadLocationInfo(FVector Location);

    //UFUNCTION(BlueprintCallable, Category = "GIS")
    void ReadJson(const FString& jsonString);

    void ReadFromFile(const FString& GridId);

    void ReadFromHttp(const FString& GridId);

    UPROPERTY(BlueprintReadWrite, Category = "GIS")
    FGridLocationInfo GridLocationInfo;


    FHttpModule* Http;
};
