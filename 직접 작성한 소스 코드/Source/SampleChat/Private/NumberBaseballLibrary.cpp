#include "NumberBaseballLibrary.h"
#include "Kismet/KismetMathLibrary.h"



FString UNumberBaseballLibrary::GenerateRandomNumber()
{
    TArray<int32> Numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    FString Result;

    for (int32 i = 0; i < 3; i++)
    {
        int32 Index = UKismetMathLibrary::RandomIntegerInRange(0, Numbers.Num() - 1);
        Result += FString::FromInt(Numbers[Index]);
        Numbers.RemoveAt(Index);
    }

    return Result;
}

FString UNumberBaseballLibrary::ExtractValidNumber(const FString& Input)
{
    FString FilteredString;
    for (int32 i = 0; i < Input.Len(); i++)
    {
        if (FChar::IsDigit(Input[i]))
        {
            FilteredString += Input[i];
        }
    }

    if (FilteredString.Len() != 3)
    {
        return TEXT("Invalid");
    }

    TSet<TCHAR> UniqueDigits;
    for (TCHAR Digit : FilteredString)
    {
        if (Digit < '1' || Digit > '9' || UniqueDigits.Contains(Digit))
        {
            return TEXT("Invalid");
        }
        UniqueDigits.Add(Digit);
    }

    return FilteredString;
}


void UNumberBaseballLibrary::EvaluateGuess(
    const FString& SecretNumber,
    const FString& Guess,
    int32 AttemptCount,
    FString& Result,
    int32& OutCount)
{
    if (Guess.Len() != 3)
    {
        Result = TEXT("Invalid input! Enter 3 unique digits (1-9).");
        return;
    }

    TSet<TCHAR> UniqueDigits;
    for (TCHAR Digit : Guess)
    {
        if (Digit < '1' || Digit > '9' || UniqueDigits.Contains(Digit))
        {
            Result = TEXT("Invalid input! Enter 3 unique digits (1-9).");
            return;
        }
        UniqueDigits.Add(Digit);
    }

    int32 Strike = 0, Ball = 0;

    for (int32 i = 0; i < 3; i++)
    {
        if (Guess[i] == SecretNumber[i])
        {
            Strike++;
        }
        else if (SecretNumber.Contains(FString(1, &Guess[i])))
        {
            Ball++;
        }
    }

    if (Strike == 3)
    {
        Result = TEXT("Win!");
        return;
    }

    if (Strike == 0 && Ball == 0)
    {
        OutCount++; // 아웃 카운트 증가
    }

    if (OutCount >= 3)
    {
        Result = TEXT("Lose!");
        return;
    }

    Result = FString::Printf(TEXT("%dS %dB %dO | Attempts: %d"), Strike, Ball, OutCount, AttemptCount);
}


void UNumberBaseballLibrary::HandleMessageFromClient(
    const FString& Input,
    FString SecretNumber,
    int32& AttemptCount,
    int32& OutCount,
    FString& Result,
    bool& bShouldReset)
{
    FString ValidNumber = ExtractValidNumber(Input);

    AttemptCount++; // 시도 횟수 증가

    if (ValidNumber == TEXT("Invalid"))
    {
        OutCount++;
        Result = TEXT("OUT! 잘못된 입력입니다.");
    }
    else
    {
        EvaluateGuess(SecretNumber, ValidNumber, AttemptCount, Result, OutCount);
    }

    bShouldReset = (Result == TEXT("Win!") || OutCount >= 3);
}

