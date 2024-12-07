#include <iostream>

using namespace std;

enum actionType {
	attack = 1,
	heal,
	multi,
	single
};

#pragma once
class unit;
class action
{
protected:
	string actionName;
	enum actionType spellType;
	int damageCoefficient;
	int mpCost;


public:
	action(); //constructor
	string getActionName();
	int getMpCost();
	int getSpellType();

	virtual void performAction(unit* attacker, unit* defender) = 0;

};

