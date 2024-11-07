#include "wizard.h"
#include "spell.h"

using namespace std;

string wizard::getName()
{
	return this->name;
}

int wizard::getHp()
{
	return this->hp;
}

int wizard::getMp()
{
	return this->mp;
}

wizard::wizard(string nameInput, spell* spellInput) 
{
	this->name = nameInput;
	this->spellName = spellInput;

	cout << this->name << " has appeared out of nowhere." << endl;
	cout << "He has complete mastery over the spell called " << spellInput->getName() << endl;
	cout << endl;
}

wizard::~wizard() //destructor
{
	cout << this->name << " has succumbed to his opponent!" << endl;
}

void wizard::attack(wizard* target)
{
	int damage = this->minDamage + ( rand() % this->maxDamage );
	int mpGain = 10 + (rand() & 20);

	cout << this->name << " has bonked " << target->name << " with his staff for " << damage << " damage!" << endl;
	cout << endl;

	target->hp -= damage;
	if (target->hp < 0)
		target->hp = 0;

	cout << this->name << " has gained " << mpGain << " MP for attacking! " << endl;
	cout << endl;

	this->mp += mpGain;
}

void wizard::castSpell(wizard* target)
{
	cout << this->name << " can cast his spell called " << this->spellName->getName() << "!" << endl;
	cout << endl;

	this->mp -= this->spellName->getMpCost();

	target->hp -= this->spellName->activate(target);
	if (target->hp < 0)
		target->hp = 0;
}

