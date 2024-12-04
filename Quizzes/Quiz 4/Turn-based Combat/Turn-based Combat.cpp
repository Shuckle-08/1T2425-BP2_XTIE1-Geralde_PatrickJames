// Turn-based Combat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

#include "unit.h"
#include "action.h"
#include "basicAttack.h"
#include "skillHeal.h"
#include "skillMulti.h"
#include "skillSingle.h"
#include "Turn-based Combat.h"

using namespace std;

void displayDetails(vector<unit>& allies, vector<unit>& enemies, vector<unit>& turnOrder)
{
	system("cls");
	cout << "Team Warcraft :" << "\n\n";
	for (int i = 0; i < allies.size(); i++) {
		allies[i].displayStats();
	}

	cout << "\n\n";

	cout << "Team Diablo :" << "\n\n";
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i].displayStats();
	}

	cout << "\n\n";

	cout << "Turn Order :" << "\n\n";
	for (const auto& unit : turnOrder) {
		cout << unit.getName() << " (Agility: " << unit.getAgi() << ")\n";
	}
}

int main()
{
	// Actions
	action* attack = new basicAttack("Bash");
	action* faceMelt = new skillMulti("Face Melt");
	action* theHunt = new skillSingle("The Hunt");
	action* jugOfLife = new skillHeal("The Jug of Life");
	action* puncturingArrow = new skillSingle("Puncturing Arrow");
	action* divinePalm = new skillHeal("Divine Palm");

	// Allies
	vector<unit> allies = {
		unit("E.T.C" , attack, faceMelt, true),
		unit("Illidan", attack, theHunt, true),
		unit("LiLi", attack, jugOfLife, true)
	};

	// Enemies
	vector<unit> enemies = {
		unit("Johanna", attack, faceMelt, false),
		unit("Valla", attack, puncturingArrow, false),
		unit("Kharazim", attack, divinePalm, false)
	};

	//Determine Turn Order
	vector<unit> turnOrder = allies;
	turnOrder.insert(turnOrder.end(), enemies.begin(), enemies.end());

	sort(turnOrder.begin(), turnOrder.end(), [](const unit& a, const unit& b) {
		return a.getAgi() > b.getAgi();
		});
	

	//Display Details
	displayDetails(allies, enemies, turnOrder);

	cout << "\n";

	srand(time(0));
	int randomTarget = rand() % 3;
	int actionSelection;

	//One Turn
	for (int i = 0; i < turnOrder.size(); i++) {
		cout << "It is " << turnOrder[i].getName() << " turn" << "\n\n";
		if (turnOrder[i].getAlliance() == false) {
			cout << "Enemy is Deciding" << "\n";
			Sleep(500);

			if (turnOrder[i].getCurrentMp() < turnOrder[i].getSpellMpCost()) {
				cout << "Enemy is Attacking" << "\n";
				//turnOrder[i].doAttack(turnOrder[i], allies[randomTarget])
			}
			else {
				cout << "Enemy is Casting Spell" << "\n";
				//turnOrder[i].castSpell(turnOrder[i], enemies[randomTarget]);
			}
		}
		else {
			turnOrder[i].displayActions();
			//system("pause");
			while (true) {
				cin >> actionSelection;
				switch (actionSelection) {
				case 1:
					cout << "Attacking" << "\n";
					//turnOrder[i].doAttack(turnOrder[i], enemies[randomTarget]);
					actionSelection = 0;
					break;
				case 2:
					cout << "Casting Spell"<< "\n";
					//turnOrder[i].castSpell(turnOrder[i], enemies[randomTarget]);
					actionSelection = 0;
					break;
				default:
					cout << "Invalid Input" << "\n";
					continue;
				}
				if (actionSelection == 0) {
					break;
				}
			}
			
		}
	}

	cout << "Huhays" << "\n\n";
	system("pause");
}