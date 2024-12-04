// Turn-based Combat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

#include "unit.h"
#include "action.h"
#include "basicAttack.h"
#include "skillHeal.h"
#include "skillMulti.h"
#include "skillSingle.h"
#include "Turn-based Combat.h"

using namespace std;

void displayDetails(std::vector<unit>& allies, std::vector<unit>& enemies, std::vector<unit>& turnOrder)
{
	system("clr");
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
	//vector<action> actions = {
	//	basicAttack("Bash"),
	//	skillMulti("Face Melt"),
	//	skillSingle("The Hunt"),
	//	skillHeal("The Jug of Life"),
	//	skillSingle("Puncturing Arrow"),
	//	skillHeal("Divine Palm")
	//}

	action* attack = new basicAttack("Bash");
	action* faceMelt = new skillMulti("Face Melt");
	action* theHunt = new skillSingle("The Hunt");
	action* jugOfLife = new skillHeal("The Jug of Life");
	action* puncturingArrow = new skillSingle("Puncturing Arrow");
	action* divinePalm = new skillHeal("Divine Palm");

	//Make Allies
	vector<unit> allies = {
		unit("E.T.C" , attack, faceMelt),
		unit("Illidan", attack, theHunt),
		unit("LiLi", attack, jugOfLife)
	};

	//Make Enemies
	vector<unit> enemies = {
		unit("Johanna", attack, faceMelt),
		unit("Valla", attack, puncturingArrow),
		unit("Kharazim", attack, divinePalm)
	};

	//Determine Turn Order
	vector<unit> turnOrder = allies;
	turnOrder.insert(turnOrder.end(), enemies.begin(), enemies.end());

	std::sort(turnOrder.begin(), turnOrder.end(), [](const unit& a, const unit& b) {
		return a.getAgi() > b.getAgi();
		});
	

	//Display Details
	displayDetails(allies, enemies, turnOrder);

	

	cout << "Huhays" << "\n\n";
	system("pause");
}