// Turn-based Combat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "unit.h"
#include "action.h"

using namespace std;


int main()
{
    // Add Allies
    vector<unit> allies = {
        unit("E.T.C" , "Guitar Smash", "Face Melt"),
        unit("Illidan" , "Blade Whirl" , "The Hunt"),
        unit("LiLi" , "Face Slap" , "Jug of Life")
    }
    // Add Allies
        vector<Allies> allies = {
            unit etc("E.T.C" , "Guitar Smash", "Face Melt"),
            unit illidan("Illidan" , "Blade Whirl" , "The Hunt"),
            unit lili("LiLi" , "Face Slap"),
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
