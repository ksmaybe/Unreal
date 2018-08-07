#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// two ints initialized to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame();
	void Reset();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FString& word)const;

	// counts bulls & cows and increases try #assuming valid guess
	FBullCowCount SubmitGuess(FString);



private:
	int32 MyCurrentTry;
	int MyMaxTries;
	bool IsIsogram(FString);
	FString MyHiddenWord;
};