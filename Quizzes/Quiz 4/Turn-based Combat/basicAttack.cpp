#include "basicAttack.h"
#include "unit.h"


void basicAttack::doBasicAttack(unit* attacker, unit* defender)
{
	srand(time(0));
	int damage, baseDamage, randomizedPow, hitPercent;

	randomizedPow = attacker->getPow() + (attacker->getPow() % 20);

	baseDamage = randomizedPow * damageCoefficient;

	damage = baseDamage - defender->getVit();

	if (damage < 1) {
		damage = 1;
	}

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
