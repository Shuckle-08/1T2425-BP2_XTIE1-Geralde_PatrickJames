#include "action.h"

action::action() //constructor
{
    //this->actionName = "actionNameInput";
    //this->damageCoefficient = 0;
    //this->mpCost = 0;
    //cout << "Made a Blank Action" << "\n\n";
}

string action::getActionName()
{
    return this->actionName;
}

int action::getMpCost()
{
    return this->mpCost;
}

int action::getSpellType()
{
    return this->spellType;
}

void action::performAction(unit* attacker, unit* defender)
{
    cout << "Executing Blank Action" << "\n";
    
}
