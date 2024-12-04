#include "skillSingle.h"

skillSingle::skillSingle(string skillName)
{
	this->actionName = skillName;
	this->damageCoefficient = 2.2;
	this->mpCost = 5;
	//cout << "Made Single Hit Skill Called " << this->actionName << " with an MP cost of " << this->mpCost << "\n\n";
}
