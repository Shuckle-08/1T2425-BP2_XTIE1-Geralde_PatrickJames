// Arena.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <Windows.h>

#include "fighter.h"

using namespace std;

void displayFighter(fighter* fighter) {
    const int labelWidth = 12; 

    cout << left;
    cout << '\n';
    cout << setw(labelWidth) << "Name" << ": " << fighter->getName() << '\n';
    cout << setw(labelWidth) << "Power" << ": " << fighter->getPow() << '\n';
    cout << setw(labelWidth) << "Vitality" << ": " << fighter->getVit() << '\n';
    cout << setw(labelWidth) << "Agility" << ": " << fighter->getAgi() << '\n';
    cout << setw(labelWidth) << "Dexterity" << ": " << fighter->getDex() << '\n';
    cout << setw(labelWidth) << "Class" << ": " << fighter->getClassName() << '\n';
    cout << '\n';
}

fighter* createFighter(int rounds) {
    string randomNames[10] = { "The Rage", "Moonlighter", "Crusher", "Big Man", "Squid Ink", "The Void", "Jeffery", "Yion", "Echo", "Balloon" };

    int randomNameSelector, randomClassSelector, scaling = 0;
    string randomizedName;

    randomNameSelector = rand() % 10;

    randomizedName = randomNames[randomNameSelector];

    randomClassSelector = 1 + rand() % 3;

    scaling += (rounds % 3) * 2;
    
    return new fighter(randomizedName, randomClassSelector, 1, scaling);
}

int main()
{
    srand(time(0));

    cout << "!!!! WELCOME TO THE ARENA !!!!" << '\n';

    string nameInput;
    int classInput, rounds = 0;

    cout << "What is your name?" << '\n';
    cin >> nameInput;
    cout << '\n';
    cout << "What class would you like to be?" << '\n';
    cout << left;
    cout << setw(20) << "[1] Warrior" << '\n';
    cout << setw(20) << "[2] Assassin" << '\n';
    cout << setw(20) << "[3] Mage" << '\n';
    cin >> classInput;
    cout << '\n';

    fighter* player = new fighter (nameInput, classInput, 0, 0);
    
    fighter* enemy = createFighter(rounds);

    while (player->getCurrentHp() > 0) {
        system("cls");
        displayFighter(player);
        displayFighter(enemy);
        Sleep(100);

        if (player->getAgi() > enemy->getAgi()) {
            player->attack(enemy);
            Sleep(100);
            if (enemy->getCurrentHp() <= 0) {
                break;
            }
            enemy->attack(player);
            Sleep(100);
        }
        else {
            enemy->attack(player);
            Sleep(100);
            if (player->getCurrentHp() < 0) {
                break;
            }
            player->attack(enemy);
            Sleep(100);
        }

        Sleep(1000);

        if (enemy->getCurrentHp() <= 0) {
            rounds++;
            player->addStats(enemy->getClass());
            delete enemy;
            fighter* enemy = createFighter(rounds);
            }
    }

    delete player;

    cout << endl;
    cout << "~~~YOU HAVE LOST~~~" << endl;
    cout << "~~~You reach round " << rounds << "~~~" << endl;
    cout << endl;
    system("pause");
}