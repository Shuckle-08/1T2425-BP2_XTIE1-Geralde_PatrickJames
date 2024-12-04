#include "skillHeal.h"

skillHeal::skillHeal(string skillName)
{
	this->actionName = skillName;
	this->damageCoefficient = 0;
	this->mpCost = 3;
	//cout << "Made Heal Skill Called " << this->actionName << " with an MP cost of " << this->mpCost << "\n\n";
}

