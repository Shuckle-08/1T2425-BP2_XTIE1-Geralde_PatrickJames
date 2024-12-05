#include "unit.h"
#include "action.h"
#include "skillHeal.h"
#include "skillMulti.h"
#include "skillSingle.h"
#include "basicAttack.h"
#include <iostream>
#include <random>
#include <iomanip>
#include <Windows.h>

using namespace std;


void unit::randomizeStats()
{
	Sleep(1000);
	default_random_engine randomizer;
	randomizer.seed(time(0));
	uniform_int_distribution<int> range(10, 20);

	this->maxHp = 100;
	this->currentHp = this->maxHp;
	this->pow = range(randomizer); cout << "pow " << this->pow << "\n";
	this->vit = range(randomizer); cout << "vit " << this->vit << "\n";
	this->agi = range(randomizer); cout << "agi " << this->agi << "\n";
	this->dex = range(randomizer); cout << "dex " << this->dex << "\n";
	this->maxMp = 50;
	this->currentMp = 0;
}

unit::unit(string nameInput, action* attackName, action* spellName, bool isAlly) //Constructor
{
	this->name = nameInput;
	this->attack = attackName;
	this->spell = spellName;
	this->isAlly = isAlly;
	

	randomizeStats();

	cout << this->name << " has entered the arena !!!" << "\n\n";
}

unit::~unit()
{
	//cout << this->name << " has died !!!" << "\n\n";
}

string unit::getName() const
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

int unit::getAgi() const
{
	return this->agi;
}

int unit::getDex()
{
	return this->dex;
}

bool unit::getAlliance()
{
	return this->isAlly;
}

int unit::getSpellMpCost()
{
	return this->spell->getMpCost();
}

void unit::displayStats()
{
	int space = 5;
	cout << right;
	cout << this->name << setw(space) << " HP " << " : " << this->currentHp << setw(space) << " MP " << " : " << this->currentMp << "\n";
}

void unit::displayActions()
{
	int space = 5;
	cout << setw(space) << " [1] " << this->attack->getActionName() << setw(space) << "[MP:" << this->attack->getMpCost() << "]" << "\n";
	cout << setw(space) << " [2] " << this->spell->getActionName() << setw(space) << "[MP:" << this->spell->getMpCost() << "]" << "\n";
}

void unit::doAttack(unit* attacker, unit* defender)
{
	cout << this->name << " has attacked !!!" << "\n";

	this->attack->performAction(attacker, defender);
}

void unit::castSpell(unit* attacker, unit* defender)
{
	cout << this->name << " has cast his spell !!!" << "\n";
	this->currentMp -= this->spell->getMpCost();
	this->spell->performAction(attacker, defender);
}

void unit::takeDamage(int damageDealt)
{
	cout << this->name << " has taken " << damageDealt << " damage !!!" << "\n\n";
	this->currentHp -= damageDealt;
}

void unit::healHp(int healAmount)
{
	cout << this->name << " has healed " << healAmount << " HP !!!" << "\n\n";
	this->currentHp += healAmount;
}

