#include <iostream>
using namespace std;

#pragma once
class action;
class unit
{
private:
	string name;
	int maxHp;
	int currentHp;
	int maxMp;
	int currentMp;
	int pow;
	int vit;
	int agi;
	int dex;
	action* attack;
	action* spell;
	void randomizeStats();

public:
	unit(string nameInput, action* (string attackName, int actionType) , action* (string spellName, int actionType));
	~unit();

	string getName();
	int getMaxHp();
	int getCurrentHp();
	int getMaxMp();
	int getCurrentMp();
	int getPow();
	int getVit();
	int getAgi();
	int getDex();

	void takeDamage(int damageDealt);
};

