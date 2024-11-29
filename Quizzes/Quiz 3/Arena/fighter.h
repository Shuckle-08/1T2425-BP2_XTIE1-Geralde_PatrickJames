#include <iostream>
using namespace std;

#pragma once
class fighter
{
private:
	string name;
	int maxHp;
	int currentHp;
	int pow;
	int vit;
	int agi;
	int dex;
	int selectedClass;

public:
	fighter(string name, int selectedClass, int player, int scaling);
	~fighter();

	string getName();
	int getMaxHp();
	int getCurrentHp();
	int getPow();
	int getVit();
	int getAgi();
	int getDex();
	int getClass();
	string getClassName();

	void attack(fighter* target);
	void addStats(int classDefeated);
	int rollDice(int min, int max);
};

