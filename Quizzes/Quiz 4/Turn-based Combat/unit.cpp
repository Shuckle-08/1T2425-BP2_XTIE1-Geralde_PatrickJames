#include "unit.h"
#include <iostream>
using namespace std;


void unit::randomizeStats()
{
	srand(time(0));

	this->maxHp = 100;
	this->pow = 1 + (rand() % 10);
	this->vit = 1 + (rand() % 10);
	this->agi = 1 + (rand() % 10);
	this->dex = 1 + (rand() % 10);
}

unit::unit(string nameInput, action* (string attackName, int actionType), action* (string spellName, int actionType))
{
	this->name = nameInput;
	this->attack = ;
	this->spell = spell;

	randomizeStats();

	cout << this->name << " has entered the arena !!!" << "\n\n";
}

unit::~unit()
{
	cout << this->name << " has died !!!" << "\n\n";
}

string unit::getName()
{
	return this->name;
}

int unit::getMaxHp()
{
	return this->maxHp;
}

int unit::getCurrentHp()
{
	return this->currentHp;
}

int unit::getMaxMp()
{
	return this->maxMp;
}

int unit::getCurrentMp()
{
	return this->currentMp;
}

int unit::getPow()
{
	return this->pow;
}

int unit::getVit()
{
	return this->vit;
}

int unit::getAgi()
{
	return this->agi;
}

int unit::getDex()
{
	return this->dex;
}

void unit::takeDamage(int damageDealt)
{
	cout << this->name << " has taken " << damageDealt << " damage !!!" << "\n\n";
	this->currentHp -= damageDealt;
}
