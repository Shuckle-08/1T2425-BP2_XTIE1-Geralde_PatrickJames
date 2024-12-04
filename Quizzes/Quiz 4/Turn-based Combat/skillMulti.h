#pragma once
#include "action.h"
class unit;
class skillMulti :
    public action
{
public:
    skillMulti(string skillName);

    void performAction(unit* attacker, unit* defender);
};

