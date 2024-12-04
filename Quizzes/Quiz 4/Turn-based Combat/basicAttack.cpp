#include "basicAttack.h"
#include "unit.h"


basicAttack::basicAttack(string attackName)
{
	this->actionName = attackName;
	this->damageCoefficient = 1;
	this->mpCost = 0;
	//cout << "Made Basic Attack Called " << this->actionName << " with an MP cost of " << this->mpCost << "\n\n";
}

void basicAttack::performAction(unit* attacker, unit* defender)
{
	srand(time(0));
	
	//Damage Calculation
	int damage, baseDamage, randomizedPow;

	randomizedPow = attacker->getPow() + (attacker->getPow() % 20);

	baseDamage = randomizedPow * damageCoefficient;

	damage = baseDamage - defender->getVit();

	if (damage < 1) {
		damage = 1;
	}

	//Crit Calculation
	int critRate = 20;
	int critDamageMultiplier = 1.2;
	int critRoll = rand() % 100;

	if (critRoll < critRate) {
		cout << this->actionName << " has CRIT !!!" << "\n";
		damage *= critDamageMultiplier;
	}

	//Hit Calculation
	int  hitPercent;
	hitPercent = attacker->getDex() / defender->getAgi();

	if (hitPercent < 20) {
		hitPercent = 20;
	}
	else if (hitPercent > 80) {
		hitPercent = 80;
	}

	int attackRoll = rand() % 100;

	if (attackRoll > hitPercent) {
		cout << attacker->getName() << " succesfully used " << this->getActionName() << " at " << defender->getName() << "\n";
		defender->takeDamage(damage);
	}
}
