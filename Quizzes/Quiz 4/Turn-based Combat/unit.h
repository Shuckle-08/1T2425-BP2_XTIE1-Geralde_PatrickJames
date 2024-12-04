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
	//int spellType;
	void randomizeStats();

public:
	unit(string nameInput, action* attackName , action* spellName);
	~unit();

	string getName() const;
	int getMaxHp();
	int getCurrentHp();
	int getMaxMp();
	int getCurrentMp();
	int getPow();
	int getVit();
	int getAgi() const;
	int getDex();

	void displayStats();
	void takeDamage(int damageDealt);
};

