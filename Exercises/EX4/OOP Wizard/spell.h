#include <iostream>
using namespace std;

#pragma once
class wizard;
class spell
{
private:
	string name;
	int mpCost = 50;
	int minDamage = 40;
	int maxDamage = 60;

public:
	string getName();
	int getMpCost();
	spell(string name); //constructor
	int activate(wizard* target);
};

