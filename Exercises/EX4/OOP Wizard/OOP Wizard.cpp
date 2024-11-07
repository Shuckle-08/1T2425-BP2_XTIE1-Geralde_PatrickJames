#include <iostream>
#include <time.h>
#include <iomanip>
#include <windows.h>
#include "wizard.h"
#include "spell.h"

using namespace std;

void displayFighters(wizard* wizard1, wizard* wizard2)
{
    cout << "Name: " << wizard1->getName() << setw(10) << "HP: " << wizard1->getHp() << setw(10) << "MP: " << wizard1->getMp() << endl;
    cout << "Name: " << wizard2->getName() << setw(10) << "HP: " << wizard2->getHp() << setw(10) << "MP: " << wizard2->getMp() << endl;
    cout << endl;
}

wizard* createWizard() {
    string nameInput, spellInput;

    cout << "What is the name of the Wizard?" << endl;
    cin >> nameInput;
    cout << "What is the name of their spell?" << endl;
    cin >> spellInput;
    cout << endl;

    return new wizard(nameInput, new spell(spellInput));
}

int main()
{
    srand(time(NULL));
 
    wizard* wizard1 = createWizard();
    wizard* wizard2 = createWizard();

    Sleep(3000);
    system("cls");

    while (wizard1->getHp() > 0 && wizard2->getHp() > 0) {
        displayFighters(wizard1, wizard2);
        Sleep(1000);
                
        if (wizard1->getHp() > 0) {
            if (wizard1->getMp() > 50) {
                wizard1->castSpell(wizard2);
                Sleep(1000);
            }
            else {
                wizard1->attack(wizard2);
                Sleep(1000);
            }
        }

        if (wizard2->getHp() > 0) {
            if (wizard2->getMp() > 50) {
                wizard2->castSpell(wizard1);
                Sleep(1000);
            }
            else {
                wizard2->attack(wizard1);
                Sleep(1000);
            }
        }
    }

    displayFighters(wizard1, wizard2);

    if (wizard1->getHp() <= 0) {
        delete wizard1;
        wizard1 = nullptr;
    }
    else {
        delete wizard2;
        wizard2 = nullptr;
    }
}
