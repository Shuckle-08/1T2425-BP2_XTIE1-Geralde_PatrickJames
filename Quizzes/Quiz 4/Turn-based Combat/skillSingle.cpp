#include "skillSingle.h"
#include "unit.h"
#include <vector>

skillSingle::skillSingle(string skillName)
{
	this->actionName = skillName;
	this->damageCoefficient = 2.2;
	this->mpCost = 5;
	//cout << "Made Single Hit Skill Called " << this->actionName << " with an MP cost of " << this->mpCost << "\n\n";
}

void skillSingle::performAction(unit* attacker, unit* defender)
{
	cout << "Executing Single Skill" << "\n";

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
