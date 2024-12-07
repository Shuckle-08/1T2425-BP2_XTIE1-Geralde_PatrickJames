#include "skillHeal.h"
#include "unit.h"

skillHeal::skillHeal(string skillName)
{
	this->actionName = skillName;
	this->spellType = heal;
	this->damageCoefficient = 0;
	this->mpCost = 3;
	//cout << "Made Heal Skill Called " << this->actionName << " with an MP cost of " << this->mpCost << "\n\n";
}

void skillHeal::performAction(unit* user, unit* target)
{
	cout << "Executing Heal Skill" << "\n";

	int healAmount = (target->getMaxHp() * 0.3);

	target->healHp(healAmount);
}