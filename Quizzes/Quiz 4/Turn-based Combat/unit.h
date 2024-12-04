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
	bool isAlly;
	void randomizeStats();

public:
	unit(string nameInput, action* attackName , action* spellName, bool isAlly);
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
	bool getAlliance();
	int getSpellMpCost();

	void displayStats();
	void displayActions();

	void doAttack(unit* attacker, unit* defender);
	void castSpell(unit* attacker, unit* defender);
	void takeDamage(int damageDealt);
	void healHp(int healAmount);
};

