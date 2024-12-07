// Turn-based Combat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <cstdlib>

#include "unit.h"
#include "action.h"
#include "basicAttack.h"
#include "skillHeal.h"
#include "skillMulti.h"
#include "skillSingle.h"
#include "Turn-based Combat.h"

void bubbleSort(vector<unit*>& units) {
    size_t n = units.size();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (units[j]->getAgi() > units[j + 1]->getAgi()) {
                // Swap the units
                std::swap(units[j], units[j + 1]);
            }
        }
    }
}

void displayDetails(vector<unit*>& warcraft, vector<unit*>& diablo, vector<unit*>& turnOrder) {
    system("cls");
    cout << "Team Warcraft :" << "\n\n";
    for (int i = 0; i < warcraft.size(); i++) {
        warcraft[i]->displayStats();
    }

    cout << "\n";

    cout << "Team Diablo :" << "\n\n";
    for (int i = 0; i < diablo.size(); i++) {
        diablo[i]->displayStats();
    }

    cout << "\n";

    cout << "Turn Order :" << "\n\n";
    for (const auto& unit : turnOrder) {
        cout << unit->getName() << " (Agility: " << unit->getAgi() << ")\n";
    }

    cout << "\n\n";
}

void cycle(std::vector<unit*>& turnOrder, std::vector<unit*>& warcraft, std::vector<unit*>& diablo) {
    srand(time(0));
    int randomTarget = rand() % 3;
    int actionSelection;

    for (int i = 0; i < turnOrder.size(); i++) {
        // Display Details
        displayDetails(warcraft, diablo, turnOrder);

        cout << "It is " << turnOrder[i]->getName() << " turn" << "\n\n";
        if (turnOrder[i]->getAlliance() == false) {
            cout << "Enemy is Deciding" << "\n";
            Sleep(500);
            if (turnOrder[i]->getCurrentMp() < turnOrder[i]->getSpellMpCost()) {
                cout << "Enemy is Attacking" << "\n\n";
                turnOrder[i]->doAttack(turnOrder[i], warcraft[randomTarget]);
            }
            else {
                cout << "Enemy is Casting Spell" << "\n\n";
                turnOrder[i]->castSpell(diablo, warcraft);
            }
        }
        else {
            turnOrder[i]->displayActions();
            while (true) {
                cin >> actionSelection;
                switch (actionSelection) {
                case 1:
                    cout << "You want to attack" << "\n\n";
                    turnOrder[i]->doAttack(turnOrder[i], diablo[randomTarget]);
                    actionSelection = 0;
                    break;
                case 2:
                    cout << "You are trying to cast your spell" << "\n\n";
                    if (turnOrder[i]->getSpellMpCost() > turnOrder[i]->getCurrentMp()) {
                        cout << "You do not have enough mana to cast your spell" << "\n";
                        cout << "Select another option" << "\n\n";
                        continue;
                    }
                    else {
                        turnOrder[i]->castSpell(warcraft, diablo);
                        actionSelection = 0;
                        break;
                    }
                default:
                    cout << "Invalid Input" << "\n\n";
                    continue;
                }
                if (actionSelection == 0) {
                    break;
                }
            }
        }
        system("pause");
    }
}

int main() {
    // Initialize classes
    action* attack = new basicAttack("Bash");
    action* faceMelt = new skillMulti("Face Melt");
    action* theHunt = new skillSingle("The Hunt");
    action* jugOfLife = new skillHeal("The Jug of Life");
    action* puncturingArrow = new skillSingle("Puncturing Arrow");
    action* divinePalm = new skillHeal("Divine Palm");

    unit* warcraft1 = new unit("E.T.C", attack, faceMelt, true);
    unit* warcraft2 = new unit("Illidan", attack, theHunt, true);
    unit* warcraft3 = new unit("LiLi", attack, jugOfLife, true);

    unit* diablo1 = new unit("Johanna", attack, faceMelt, false);
    unit* diablo2 = new unit("Valla", attack, puncturingArrow, false);
    unit* diablo3 = new unit("Kharazim", attack, divinePalm, false);

    // Warcraft team
    vector<unit*> warcraft = {
        warcraft1,
        warcraft2,
        warcraft3
    };

    // Diablo team
    vector<unit*> diablo = {
        diablo1,
        diablo2,
        diablo3
    };

    // Determine Turn Order
    vector<unit*> turnOrder = {
        warcraft1,
        warcraft2,
        warcraft3,
        diablo1,
        diablo2,
        diablo3
    };

    bubbleSort(turnOrder);

    while (!warcraft.empty()) {
        cycle(turnOrder, warcraft, diablo);
    }

    cout << "Game Over!" << "\n\n";
    system("pause");
}
