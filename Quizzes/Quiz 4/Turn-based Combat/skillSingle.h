#pragma once
#include "action.h"
#include <vector>
class unit;
class skillSingle :
    public action
{
public:
    skillSingle(string skillName);

    void performAction(unit* attacker, unit* defender);

};

