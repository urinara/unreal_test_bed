// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Json.h"
#include <Serialization/JsonSerializer.h>

AMyPlayerController::AMyPlayerController()
{
    UE_LOG(LogTemp, Error, TEXT("MyPlayerController constructor"));
}

void AMyPlayerController::ReadLocationInfo(FVector Location)
{
    UE_LOG(LogTemp, Error, TEXT("GridId=%f, %f, %f"), Location.X, Location.Y, Location.Z);

    FString GridId = FString::Printf(TEXT("%06d_%06d_%05d_%05d"), 2000, 2000, static_cast<int>(Location.X), static_cast<int>(Location.Y));
    ReadFromFile(GridId);

    UE_LOG(LogTemp, Error, TEXT("URL=%s"), *GridLocationInfo.URL);
}

void AMyPlayerController::ReadJson(const FString& JsonString)
{
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
    TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(*JsonString);

    FString URL = TEXT("");
    if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
    {
        GridLocationInfo.URL = JsonObject->GetStringField(TEXT("url"));
        GridLocationInfo.UFID = JsonObject->GetStringField(TEXT("ufid"));
        GridLocationInfo.Attribute0 = JsonObject->GetStringField(TEXT("attribute_0"));
        GridLocationInfo.Attribute1 = JsonObject->GetStringField(TEXT("attribute_1"));
    }
}

void AMyPlayerController::ReadFromFile(const FString& GridId)
{
    UE_LOG(LogTemp, Error, TEXT("GridId=%s"), *GridId);

    FString JsonDir = FPaths::CloudDir();
    FString JsonFileName = "location_info.json";

    FString JsonPath = JsonDir + "/" + JsonFileName;
    UE_LOG(LogTemp, Error, TEXT("JsonPath=%s"), *JsonPath);

    FString JsonString;
    FFileHelper::LoadFileToString(JsonString, *JsonPath);
    UE_LOG(LogTemp, Error, TEXT("JsonRead=%s"), *JsonString);

    ReadJson(JsonString);
}

void AMyPlayerController::ReadFromHttp(const FString& GridId)
{

}


