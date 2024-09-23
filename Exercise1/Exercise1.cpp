// Exercise 1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <time.h>

using namespace std;

void bet(int& gold, int& betAmount) {
	int input;
	cout << "You have " << gold << " gold." << endl;
	cout << "How much gold do you want to bet?" << endl;
	cin >> input;
	betAmount = input;

	if (input < 0 || input > gold) {
		cout << "Invalid Bet" << endl;
		system("pause");
		system("cls");
		bet(gold, betAmount);
	}
	else {
		gold -= input;
		cout << "You bet " << input << " gold" << endl;
		system("pause");
		system("cls");
	}
}

int rollDice(int minRoll, int maxRoll) {
	int dice1, dice2;

	dice1 = rand() % (maxRoll - minRoll + 1) + minRoll;
	cout << "The first dice rolled a " << dice1 << endl;
	system("pause");
	cout << endl;

	dice2 = rand() % (maxRoll - minRoll + 1) + minRoll;
	cout << "The secondd dice rolled a " << dice2 << endl;
	system("pause");
	cout << endl;

	return dice1 + dice2;
}

void payout(int& gold, int playerRoll, int aiRoll, int betAmount) {
	cout << betAmount << endl;
	if (playerRoll == 2) {
		if (playerRoll == aiRoll) {
			cout << "~~~ DRAW ~~~" << endl;
		}
		else {
			gold = +betAmount * 3;
			cout << "You Rolled Snake Eyes" << endl;
			cout << "You won " << betAmount * 3 << "gold" << endl;
		}
	}
	else if (playerRoll > aiRoll) {
		gold += betAmount;
		cout << "You won " << betAmount << " gold" << endl;
	}
	else if (aiRoll > playerRoll) {
		gold -= betAmount;
		cout << "You lost " << betAmount << " gold" << endl;
	}
	else {
		cout << "~~~ DRAW ~~~" << endl;
	}
	system("pause");
	system("cls");
}

void playRound(int& gold, int minRoll, int maxRoll, int& playerRoll, int& aiRoll, int betAmount) {
	bet(gold, betAmount);

	cout << "You are rolling the Dice" << endl << endl;
	playerRoll = rollDice(minRoll, maxRoll);
	cout << "You rolled a total of " << playerRoll << endl;
	system("pause");
	cout << endl;

	cout << "AI is rolling the Dice" << endl << endl;
	aiRoll = rollDice(minRoll, maxRoll);
	cout << "The AI rolled a total of " << aiRoll << endl;
	system("pause");
	cout << endl;

	payout(gold, playerRoll, aiRoll, betAmount);
}

int main()
{
	srand(time(NULL));

	//Initialize
	int maxRoll = 6; int minRoll = 1;
	int playerRoll, aiRoll;
	int betAmount = 0;
	int gold = 1000;

	while (gold != 0) {
		playRound(gold, minRoll, maxRoll, playerRoll, aiRoll, betAmount);
	}

	cout << "You lost ALL your gold";
	system("pause");
	system("cls");
}