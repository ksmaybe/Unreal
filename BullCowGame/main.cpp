#include <iostream>
#include <string>

using namespace std;

int main()
{	
	constexpr int WORD_LENGTH = 5;
	cout << "Hello and welcome to myshit\n";
	cout << "Take a dumb guess at a " << WORD_LENGTH << "-letter isogram, asshole!\n";

	string Guess = "";
	cout << "Guess: ";
	cin >> Guess;

	return 0;
}
