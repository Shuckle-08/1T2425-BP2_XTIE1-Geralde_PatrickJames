#pragma once
#include "action.h"
class unit;
class skillHeal :
    public action
{
public:
    skillHeal(string skillName);

    void performAction(unit* attacker, unit* defender);
};

