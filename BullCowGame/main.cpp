/*  Consle executable of BullCow class, view in MVC pattern. Responsible for use interaction.
 *  Game Logic in 
 */

#include <iostream>
#include <string>
#include "FBullCowGame.h"

FBullCowGame BCGame;


void PrintIntro()
{
	const int32 WORD_LENGTH = BCGame.GetHiddenWordLength();
	std::cout << "Hello and welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Take a dumb guess at a " << WORD_LENGTH << "-letter isogram, asshole!\n";
	std::cout << std::endl;
}

FString GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	FString Guess;
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	getline(std::cin, Guess);

	return Guess;
}

void PlayGame() 
{

	int32 MaxTries = BCGame.GetMaxTries();
	for (int32 i = 0; i < MaxTries; i++) 
	{
		FString Guess= GetGuess();          // get guess
		 // submit guess to game and receive counts

		if (BCGame.CheckGuessValidity(Guess))
		{
			FBullCowCount BCCount = BCGame.SubmitGuess(Guess);
			// print number of bulls and cows
			std::cout << "Bulls = " << BCCount.Bulls << std::endl;
			std::cout << "Cows = " << BCCount.Cows << std::endl
				<< std::endl;
		} // space between guesses
		else
		{
			std::cout << "Invalid input, please try again." << std::endl;
			i--;
		}
	}
}
// TODO summarise game


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	FString Response;
	getline(std::cin, Response);
	std::cout << std::endl << std::endl;
	return (Response[0] == 'y' || Response[0] == 'Y');
}

int main()
{	
	int32 x = rand() % 100;

	do
	{
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());

	std::cout << "Hello!";
	return 0;
}
