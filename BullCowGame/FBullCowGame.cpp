#include "FBullCowGame.h"


FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
}

int FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry()const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString& word) const
{
	return (word.length()==MyHiddenWord.length());
}

// receives a valid guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString)
{
	MyCurrentTry++; //increment the turn number

	FBullCowCount BCCount; // setup return variable
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++) {
		// loop through all letters in the guess
		for (int32 j = 0; j < HiddenWordLength; j++) {
			// compare letters against the hidden word
				// if match, increment bulls if thy're in the same place
				// increment cows if not
		}
	}
	return BCCount;
}

bool FBullCowGame::IsIsogram(FString)
{
	return false;
}
