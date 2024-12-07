#include "skillMulti.h"
#include "unit.h"

skillMulti::skillMulti(string skillName)
{
	this->actionName = skillName;
	this->spellType = multi;
	this->damageCoefficient = 0.9;
	this->mpCost = 4;
	//cout << "Made Multi Hit Skill Called " << this->actionName << " with an MP cost of " << this->mpCost << "\n\n";
}

void skillMulti::performAction(unit* attacker, unit* defender)
{
	cout << "Executing Multi Skill" << "\n";

	srand(time(0));

	//Damage Calculation
	int damage, baseDamage, randomizedPow;

	randomizedPow = attacker->getPow() + (attacker->getPow() % 20);

	baseDamage = randomizedPow * damageCoefficient;

	damage = baseDamage - defender->getVit();

	if (damage < 1) {
		damage = 1;
	}

	cout << attacker->getName() << " succesfully used " << this->getActionName() << " at " << defender->getName() << "\n";
	defender->takeDamage(damage);
}
