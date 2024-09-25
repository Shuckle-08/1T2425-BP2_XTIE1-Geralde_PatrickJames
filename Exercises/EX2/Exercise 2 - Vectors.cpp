// Exercise 2 - Vectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<time.h>
#include<vector>

using namespace std;

void fillInv(vector<string>& inventory) {
    int rnd;

    cout << "Filling up your inventory..." << endl;
    for (int x = 0; x < 10;x++) {
        rnd = rand() % 4 + 1;
        switch (rnd) {
        case 1:
            inventory.push_back("RedPotion");
            break;
        case 2:
            inventory.push_back("Elixir");
            break;
        case 3:
            inventory.push_back("EmptyBottle");
            break;
        case 4:
            inventory.push_back("BluePotion");
            break;
        }
    }
    system("pause");
    system("cls");
}

void displayInv(vector<string> inventory) {
    system("cls");
    cout << "Your Inventory: " << endl;
    for (int x = 0; x < inventory.size(); x++) {
        cout << "Item " << x + 1 << " : " << inventory[x] << endl;
    }
}

int countItem(vector<string> inventory) {
    cout << "The size of your inventory is " << inventory.size() << endl;
    cout << endl;
    system("pause");
    return inventory.size();
}

void removeItem(vector<string>& inventory) {
    int index;


    displayInv(inventory);
    cout << endl;
    cout << "Which item would you like to remove?" << endl;
    cin >> index;
    if (index > inventory.size() || index < 0) {
        cout << "Invalid Item to remove";
        system("pause");
        removeItem(inventory);
    }
    inventory.erase(inventory.begin() + index);
    cout << "Successfully Removed Item" << endl;
    system("pause");
}

int main()
{

    srand(time(NULL));

    vector<string> inventory;

    fillInv(inventory);
    displayInv(inventory);
    cout << endl;
    countItem(inventory);
    cout << endl;

    removeItem(inventory);
    displayInv(inventory);


    system("pause");
    system("cls");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
