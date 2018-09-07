#include "FBullCowGame.h"
#include <cctype>


FBullCowGame::FBullCowGame()
{
	Reset();

}

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	const FString HIDDEN_WORD = "donkey";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	int32 length = MyHiddenWord.length();
	return length;
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

EWordStatus FBullCowGame::CheckGuessValidity(FString& word) const
{

	return EWordStatus::OK;
}

// receives a valid guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++; //increment the turn number

	FBullCowCount BCCount; // setup return variable
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++) {
		// loop through all letters in the guess
		for (int32 j = 0; j < HiddenWordLength; j++) {
			// compare letters against the hidden word
			if (Guess[j] == MyHiddenWord[i]) {
			// if match, increment bulls if they're in the same place
				if (i == j) {
					BCCount.Bulls++;
				}
			// increment cows if not
				else BCCount.Cows++;
			}
		}
	}
	return BCCount;
}

bool FBullCowGame::IsIsogram(FString)
{
	return false;
}
