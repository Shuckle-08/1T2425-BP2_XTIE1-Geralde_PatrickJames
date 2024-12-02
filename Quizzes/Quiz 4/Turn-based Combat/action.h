#include <iostream>
using namespace std;



#pragma once
class action
{
protected:
	string actionName;
	int damageCoefficient;
	enum actionType {
		basicAttack = 1,
		skillMulti = 2,
		skillSingle = 3,
		skillHeal = 4
	};

public:
	action(string actionNameInput, int actionTypeInput); //constructor
	string getActionName();

};

