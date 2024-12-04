#include "skillMulti.h"

skillMulti::skillMulti(string skillName)
{
	this->actionName = skillName;
	this->damageCoefficient = 0.9;
	this->mpCost = 4;
	//cout << "Made Multi Hit Skill Called " << this->actionName << " with an MP cost of " << this->mpCost << "\n\n";
}
