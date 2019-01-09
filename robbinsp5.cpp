/*
 * robbinsp5.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: Alexandria
 */


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//function prototype
int determineWinner(int playerChoice, int computerChoice);

int main()
{
//variables
	const int minValue = 0;
	const int maxValue = 4;
	int winner;
	int playerChoice;
	int computerChoice;
	char answer;
	char playAgain;
	int totalPlays = 0;
	int playerWins = 0;
	int ties = 0;

//ask user if they wanna play
		cout << "Do you want to play a game? (Y/N): ";
		cin >> answer;

//if they say yes
			if (answer == 'Y' || answer == 'y')
				do {{
				cout << "Let's play Rock-Paper-Scissors-Lizard-Spock!" << endl;
				cout << "----------------\n";
				cout << "Here are your options!\n";
				cout << "----------------\n";
				cout << "0 \t ROCK\n";
				cout << "1 \t PAPER\n";
				cout << "2 \t SCISSORS\n";
				cout << "3 \t SPOCK\n";
				cout << "4 \t LIZARD\n";
				cout << "----------------\n";
				cout << "What will you play? (0-4): ";
				cin >> playerChoice;

//make computer choice
				unsigned seed = time(0);
				srand(seed);
				computerChoice = (rand() % (maxValue - minValue + 1)) + minValue;

				cout << "You have chosen " << playerChoice << "." << endl;
				cout << "The computer has chosen " << computerChoice << "." << endl;

//determine who wins
				winner = determineWinner(playerChoice, computerChoice);

				if (winner == 1)
					{totalPlays++;
					playerWins++;
					cout << "You win!" << endl;}
				else if (winner == -1)
					{totalPlays++;
					cout << "You lose!" << endl;}
				else if (winner == 0)
					{totalPlays++;
					ties++;
					cout << "It's a tie!" << endl;}
				else if (winner == 2)
					cout << "That's cheating! Game over!" << endl;

//show final results
				cout << "----------------\n";
				cout << "Here are the results!\n";
				cout << "Total Plays = " << totalPlays << endl;
				cout << "Player Wins = " << playerWins << endl;
				cout << "Ties = " << ties << endl;
				cout << "----------------\n";

//ask if user wants to play again
				cout << "Want to play again? (Y/N)";
				cin >> playAgain;

				}} while (playAgain == 'Y' || playAgain == 'y');

			else
				cout << "OK then." << endl;

	return 0;
}

int determineWinner(int num1, int num2)
{
	if (num1 == 0 && (num2 == 4 || num2 == 2))
		return 1;
	else if (num1 == 0 && (num2 == 1 || num2 == 3))
		return -1;
		else if (num1 == 1 && (num2 == 3 || num2 == 0))
			return 1;
		else if (num1 == 1 && (num2 == 4 || num2 == 2))
			return -1;
			else if (num1 == 2 && (num2 == 1 || num2 == 4))
				return 1;
			else if (num1 == 2 && (num2 == 0 || num2 == 3))
				return -1;
				else if (num1 == 3 && (num2 == 0 || num2 == 2))
					return 1;
				else if (num1 == 3 && (num2 == 1 || num2 == 4))
					return -1;
					else if (num1 == 4 && (num2 == 1 || num2 == 3))
						return 1;
					else if (num1 == 4 && (num2 == 0 || num2 == 2))
						return -1;
					else if (num1 >= 4)
						return 2;
					else
						return 0;
}



