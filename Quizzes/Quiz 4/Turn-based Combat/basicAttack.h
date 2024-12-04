#pragma once
#include "action.h"
class unit;
class basicAttack :
    public action
{
public:
    basicAttack(string attackName);
    void performAction(unit* attacker, unit* defender);
};

