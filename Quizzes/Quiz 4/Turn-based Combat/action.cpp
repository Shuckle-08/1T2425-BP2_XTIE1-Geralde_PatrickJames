#include "action.h"

action::action(string actionNameInput, int actionTypeInput) //constructor
{
    this->actionName = actionNameInput;
    switch (actionTypeInput) {
    case 1: //basicAttack
        this->damageCoefficient = 1;
        break;
    case 2: //skillMulti
        this->damageCoefficient = 0.9;
        break;
    case 3: //skillSingle
        this->damageCoefficient = 2.2;
        break;
    case 4: //skillHeal
        this->damageCoefficient = 0;
        break;
    default: //
        this->damageCoefficient = 0;
        break;
    }
}

string action::getActionName()
{
    return this->actionName;
}
