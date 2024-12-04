#include <iostream>
using namespace std;



#pragma once
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

};

