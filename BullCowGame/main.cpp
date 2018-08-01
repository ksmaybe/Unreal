#include <iostream>
#include <string>
#include "FBullCowGame.h"

using namespace std;

void PrintIntro()
{
	constexpr int WORD_LENGTH = 9;
	cout << "Hello and welcome to Bulls and Cow, a fun word game.\n";
	cout << "Take a dumb guess at a " << WORD_LENGTH << "-letter isogram, asshole!\n";
	cout << endl;
}

string GetGuess()
{
	string Guess;
	cout << "Enter your guess: ";
	getline(cin, Guess);

	return Guess;
}

void PlayGame() 
{
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 0; i < NUMBER_OF_TURNS; i++) 
	{
		string Guess= GetGuess();
		cout << "Your guess was: " << Guess << endl;
		cout << endl;
	}
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again? (y/n) ";
	string Response;
	getline(cin, Response);
	cout << endl << endl;
	return(Response[0] == 'y' || Response[0] == 'Y');
}

int main()
{	
	int x = rand() % 100;

	do
	{
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());

	
	return 0;
}
