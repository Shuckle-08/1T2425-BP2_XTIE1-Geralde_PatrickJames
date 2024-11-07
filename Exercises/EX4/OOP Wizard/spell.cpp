#include "spell.h"
#include "wizard.h"

using namespace std;

string spell::getName() 
{
	return this->name;
}

int spell::getMpCost()
{
	return this->mpCost;
}

spell::spell(string nameInput) 
{
	name = nameInput;
}

int spell::activate(wizard* target)
{
	int damage = this->minDamage + ( rand() % this->maxDamage );
	
	cout << this->name << " spell has hit " << target->getName() << " for " << damage << " damage!" << endl;
	cout << endl;
	
	return damage;
}
