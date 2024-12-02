#pragma once
#include "action.h"
class unit;
class basicAttack :
    public action
{
public:
    void doBasicAttack(unit* attacker, unit* defender);
};

