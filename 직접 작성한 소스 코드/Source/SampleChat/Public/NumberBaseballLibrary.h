#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NumberBaseballLibrary.generated.h"

UCLASS()
class SAMPLECHAT_API UNumberBaseballLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "NumberBaseball")
    static FString GenerateRandomNumber();

    /** 1~9 중복 없는 숫자 3자리만 추출. 유효하지 않으면 "Invalid" 반환 */
    UFUNCTION(BlueprintCallable, Category = "NumberBaseball")
    static FString ExtractValidNumber(const FString& Input);

    UFUNCTION(BlueprintCallable, Category = "Number Baseball")
    static void EvaluateGuess(
        const FString& SecretNumber,
        const FString& Guess,
        int32 AttemptCount,
        FString& Result,
        int32& OutCount
    );

    UFUNCTION(BlueprintCallable, Category = "Number Baseball")
    static void HandleMessageFromClient(
        const FString& Input,
        FString SecretNumber,
        int32& AttemptCount,
        int32& OutCount,
        FString& Result,
        bool& bShouldReset
    );
};

