#include <iostream>
using namespace std;

#pragma once
class spell;
class wizard
{
private:
	string name;
	int hp = 250;
	int mp = 0;
	int minDamage = 10;
	int maxDamage = 15;
	spell* spellName;

public:
	string getName();
	int getHp();
	int getMp();
	wizard(string name, spell* spell); //constructor
	~wizard(); //destructor
	void attack(wizard* target);
	void castSpell(wizard* target);
};