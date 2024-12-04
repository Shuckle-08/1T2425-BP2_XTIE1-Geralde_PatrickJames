#include <iostream>

using namespace std;



#pragma once
class unit;
class action
{
protected:
	string actionName;
	int damageCoefficient;
	int mpCost;


public:
	action(); //constructor
	string getActionName();
	int getMpCost();

	virtual void performAction(unit* attacker, unit* defender) = 0;

};

