#include "fighter.h"
#include <Windows.h>

using namespace std;

fighter::fighter(string name, int selectedClass, int player, int scaling) //constructor
{
	this->name = name;
	this->maxHp = 100;
	this->currentHp = this->maxHp;
	this->pow = this->rollDice(10, 15);
	this->vit = this->rollDice(10, 15);
	this->agi = this->rollDice(10, 15);
	this->dex = this->rollDice(10, 15);
	this->selectedClass = selectedClass;

	if (player == 0) {
		//cout << "adding player buff" << endl;
		this->pow += this->rollDice(5, 15);
		this->vit += this->rollDice(5, 15);
		this->agi += this->rollDice(5, 15);
		this->dex += this->rollDice(5, 15);
	}
	else if (player == 1){
		//cout << "adding enemy scaling" << endl;
		this->pow += this->rollDice(1, 3) + scaling;
		this->vit += this->rollDice(1, 3) + scaling;
		this->agi += this->rollDice(1, 3) + scaling;
		this->dex += this->rollDice(1, 3) + scaling;
	}

	cout << this->name << " the " << this->getClassName() << " has entered the Arena." << "\n\n";
	system("pause");
	cout << "\n\n";
}

fighter::~fighter() //destructor
{
	cout << this->name << " has fainted !!!" << '\n';
}

string fighter::getName()
{
	return this->name;
}

int fighter::getMaxHp()
{
	return this->maxHp;
}

int fighter::getCurrentHp()
{
	return this->currentHp;
}

int fighter::getPow()
{
	return this->pow;
}

int fighter::getVit()
{
	return this->vit;
}

int fighter::getAgi()
{
	return this->agi;
}

int fighter::getDex()
{
	return this->dex;
}

int fighter::getClass()
{
	return this->selectedClass;
}

string fighter::getClassName()
{
	string className;

	switch (this->selectedClass) {
	case 1:
		className = "Warrior";
		return className;
		break;
	case 2:
		className = "Assassin";
		return className;
		break;
	case 3:
		className = "Mage";
		return className;
		break;
	default:
		break;
	}

}

void fighter::attack(fighter* target)
{
	srand(time(NULL));

	int damage;
	bool advantage;


	if (this->selectedClass = 1) {
		if (target->selectedClass = 2) {
			advantage = true;
		}
	}
	else if (this->selectedClass = 2) {
		if (target->selectedClass = 3) {
			advantage = true;
		}
	}
	else if (this->selectedClass = 3) {
		if (target->selectedClass = 1) {
			advantage = true;
		}
	}
	else {
		advantage = false;
	}
		
		 
	if (advantage = true) {
		damage = (this->pow - target->vit) * 1.5;
	}
	else {
		damage = (this->pow - target->vit);
	}

	if (damage < 1) {
		damage = 1;
	}

	damage += (5 + (rand() % 20)); //Damage Inflator

	//cout << damage << endl;

	int hitChance = (this->dex / target->agi) * 100;

	if (hitChance < 20) {
		hitChance = 20;
	}
	else if (hitChance > 80) {
		hitChance = 80;
	}

	int attack = rand() % 100; 
	attack += (10 + (rand() % 10)); //Attack Chance Inflator

	//cout << hitChance << " * " << attack << endl;

	if (attack >= hitChance) {
		target->currentHp -= damage;
		if (target->currentHp < 0) {
			target->currentHp = 0;
		}
		cout << this->name << " attacks " << target->name << " for " << damage << " damage!!!" << "\n";
		cout << target->name << " HP remaining : " << target->currentHp << "\n\n";
	}
	else {
		cout << this->name << " attack missed !!!" << "\n";
		cout << target->name << " HP remaining : " << target->currentHp << "\n\n";
	}
}

void fighter::addStats(int classDefeated)
{
	//cout << "adding stats" << endl;

	switch (classDefeated) {
	case 1:
		this->pow += 3;
		this->vit += 3;
		cout << this->name << " got +3 POWER and +3 VITALITY!!!" << "\n\n";
		break;
	case 2:
		this->agi += 3;
		this->dex += 3;
		cout << this->name << " got +3 AGILITY and +3 DEXTERITY!!!" << "\n\n";;
		break;
	case 3:
		this->pow += 5;
		cout << this->name << " got +5 POWER!!!" << "\n\n";
		break;
	default:
		break;
	}

	cout << this->name << " has healed 30% of his HP." << "\n\n";
	this->currentHp += this->maxHp * .30;
}

int fighter::rollDice(int min, int max)
{
	srand((unsigned int)time(NULL));

	cout << "\n\n";
	cout << "~~~Rolling Stats~~~";
	cout << "\n\n";
	Sleep(1000);

	int diceRoll= rand() % (max - min + 1) + min;
	return diceRoll;
}

