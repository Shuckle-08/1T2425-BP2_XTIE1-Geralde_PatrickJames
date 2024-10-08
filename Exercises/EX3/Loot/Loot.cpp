#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

struct Item {
    string name;
    int goldValue;
};

void enterAgain(bool& loot, int& multiplier) {
    string input;
    cout << "Do you want to keep looting? (yes/no): ";
    cin >> input;

    for (char& c : input) {
        c = tolower(c);
    }

    if (input == "no" || input == "n") {
        cout << endl;
        loot = false;
    }
    else if (input == "yes" || input == "y") {
        multiplier *= 2;
        cout << endl;
    }
    else {
        cout << "~~~ INVALID SELECTION ~~~" << endl;
        cout << endl;
        return enterAgain(loot, multiplier);
    }
}

void enterDungeon(int& money, vector<Item>& inventory) {
    int picker;
    bool loot = true;
    int totalLootValue = 0;
    int multiplier = 1;

    if (money < 0) {
        cout << "You do not have enough money to enter the Dungeon." << endl;
        return;
    }
    else {
        cout << "Entering the Dungeon..." << endl;
        Sleep(1000);
        cout << endl;
        money -= 25;
    }

    while (loot) {
        cout << "Looting Dungeon..." << endl;
        Sleep(1500);
        cout << endl;

        picker = rand() % 5;

        switch (picker) {
        case 0: {
            Item ore;
            ore.name = "Mitril Ore";
            ore.goldValue = 100;
            inventory.push_back(ore);
            totalLootValue += ore.goldValue * multiplier;
            cout << "You found " << ore.name << " worth " << ore.goldValue * multiplier << " gold." << endl;
            break;
        }
        case 1: {
            Item talon;
            talon.name = "Sharp Talon";
            talon.goldValue = 50;
            inventory.push_back(talon);
            totalLootValue += talon.goldValue * multiplier;
            cout << "You found " << talon.name << " worth " << talon.goldValue * multiplier << " gold." << endl;
            break;
        }
        case 2: {
            Item leather;
            leather.name = "Thick Leather";
            leather.goldValue = 25;
            inventory.push_back(leather);
            totalLootValue += leather.goldValue * multiplier;
            cout << "You found " << leather.name << " worth " << leather.goldValue * multiplier << " gold." << endl;
            break;
        }
        case 3: {
            Item jello;
            jello.name = "Jellopy";
            jello.goldValue = 5;
            inventory.push_back(jello);
            totalLootValue += jello.goldValue * multiplier;
            cout << "You found " << jello.name << " worth " << jello.goldValue * multiplier << " gold." << endl;
            break;
        }
        case 4: {
            cout << "You found a Cursed Stone!" << endl;
            cout << "All your items are now cursed and lost!" << endl;
            cout << "You decided to exit the dungeon to get more gear" << endl;
            inventory.clear();
            loot = false;
            system("pause");
            system("cls");
            return;
        }
        default:
            cout << "You found nothing." << endl;
            break;
        }

        enterAgain(loot, multiplier);
    }

    money += totalLootValue;
    cout << "You gained " << totalLootValue << " gold from looting!" << endl;
}

int main() {
    srand(time(NULL));

    int money = 50;
    vector<Item> inventory;

    while (money >= 25) {
        cout << "Current Gold: " << money << " gold." << endl;
        cout << endl;
        enterDungeon(money, inventory);
    }

    if (money < 25) {
        cout << "You do not have enough money to enter the Dungeon" << endl;
        cout << "~~~ YOU LOST ~~~" << endl;
    }
    else if (money >= 500) {
        cout << "You have earned 500 GOLD" << endl;
        cout << "~~~ YOU WON ~~~" << endl;
    }

    system("pause");
    system("cls");
    return 0;
}