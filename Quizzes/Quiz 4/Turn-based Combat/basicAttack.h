#pragma once
#include "action.h"
class unit;
class basicAttack :
    public action
{
public:
    basicAttack(string attackName);
    void doBasicAttack(unit* attacker, unit* defender);
};

