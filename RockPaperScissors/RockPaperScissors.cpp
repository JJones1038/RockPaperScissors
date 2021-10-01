#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';





void printInsturctions() {
	cout << "==================================================================\n";
	cout << "Welcome to the game of Rock, Paper, and Scissors.\n";
	cout << "This is a game for two players, which you will be\n";
	cout << "playing against the computer. With each game, both\n";
	cout << "players will select on of the following weapons\n";
	cout << endl;
	cout << "ROCK, PAPER, or SCISSORS\n";
	cout << endl;
	cout << "The winner is determined as follows:\n";
	cout << "*If both players select the same weapon, the game is a tie.\n";
	cout << "*ROCK bluts SCISSORS, so the player who selects ROCK wins.\n";
	cout << "*PAPER wraps ROCK, so the player who selects PAPER wins.\n";
	cout << "*SCISSORS cuts PAPER, so the player who selects SCISSORS wins\n";
	cout << endl;
	cout << "With each turn, select 'R' for ROCK, 'P' for PAPER, or\n";
	cout << "'S' for SCISSORS, and the press ENTER.\n";
	cout << "You may quit at anytime.\n";
	cout << "==================================================================\n";
}

// The computer selects a weapon at random.
char getComputerWeapon() {
	srand(time(0));
	int num = rand() % 3 + 1;
	if (num == 1) return 'r';
	if (num == 2) return 'p';
	if (num == 3) return 's';
}

// User selects their weapon.
char getUserWeapon() {
	char choice;
	cout << "Choose Your Weapon\n";
	cout << "(r) for ROCK" << endl << "(p) for PAPER" << endl << "(s) for SCISSORS" << endl;
	cin >> choice;
	while (choice != 'r' && choice != 'p' && choice != 's')
	{
		cout << "Please enter one of the following options only. " << endl;
		cout << "(r) for ROCK" << endl << "(p) for PAPER" << endl << "(s) for SCISSORS" << endl;
		cin >> choice;
	}
	return choice; 
}

//Shows what the user and the computer selected as their weapon
char showWeapon(char option) {
	if (option == 'r') cout << "ROCK" << endl;
	if (option == 'p') cout << "PAPER" << endl;
	if (option == 's') cout << "SCISSORS" << endl;
	return option;
}

char selectWinner(char uChoice, char cChoice) {
	if (uChoice == ROCK && cChoice == PAPER)
	{
		cout << "Computer Wins! Paper wraps Rock." << endl;
	}
	else if (uChoice == PAPER && cChoice == SCISSORS)
	{
		cout << "Computer Wins! Scissors cut Paper." << endl;
	}
	else if (uChoice == SCISSORS && cChoice == ROCK)
	{
		cout << "Computer Wins! Rock smashes Scissors." << endl;
	}
	else if (uChoice == ROCK && cChoice == SCISSORS)
	{
		cout << "You Win! Rock smashes Scissors." << endl;
	}
	else if (uChoice == PAPER && cChoice == ROCK)
	{
		cout << "You Win! Paper wraps Rock" << endl;
	}
	else if (uChoice == SCISSORS && cChoice == PAPER)
	{
		cout << "You Win! Scissors cut Paper." << endl;
	}
	else
	{
		cout << "It is a Tie! Play again to win the game." << endl;
	}
	return (uChoice, cChoice);
}

int main() {
	int response;
	char uChoice;  //variable to store the users choice of weapon
	char cChoice;  //variable to store the computers choice of weapon

	printInsturctions(); //Brief explanation of the game and how it is played.

	cout << "Enter Y/y to play the game: ";  //ask the user if they want to play the game.
	cin >> response;
	cout << endl;

	while (response == 'Y' || response == 'y')
	{
		uChoice = getUserWeapon();
		cout << "Player Picked: " << showWeapon(uChoice) << endl;

		cChoice = getComputerWeapon();
		cout << "Computer Picked: " << showWeapon(cChoice) << endl;

		selectWinner(uChoice, cChoice);
	}
	return 0;
}
