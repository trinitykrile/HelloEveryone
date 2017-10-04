//
//  main.cpp
//  TextGame
//
//  Created by Trinity Krile on 9/28/17.
//  Copyright © 2017 Trinity Krile. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "What is your name?";
    string name;
    cin >> name;
    cout << name << ", you are in a room with three doors, one to the north, one to the west, and one to the east.";
    
    cout << name << ", the Great Soceror has recruited you for a special mission. You must find a magical paper clip and bring it to him./n If you are successful, he will reward you with a lifetime of riches.";
    
    string location = "start";
    if (location == "start")
    {
     cout << "You are at the start.";
    }
    
    cout << "You can go through a door ('north', 'east', 'west') or 'explore' the current room.";
    string UserInput = "Hi";
    cin >> UserInput;
    if (UserInput == "explore")
    {
        cout << "There is an oven, a desk, and a table. You can explore the 'oven', 'desk', or 'table', or 'exit' exploration.";
        cin >> UserInput;
        if (UserInput == "exit")
        {
            string location = "start";
            cout << "You are at the start.";
        }
        else if (UserInput == "desk")
        {
            cout << "Looks like there are some pencils and line paper";
            
        }
    }
    else if (UserInput == "north")
    {
        cout << "_";
    }
    else if (UserInput == "west")
    {
        cout << "_";
    }
    else if (UserInput == "east")
    {
        cout << "_";
    }
    else if (UserInput == "south")
    {
        cout << "You ran into a wall. Unfortunatly, the socerer no longer thinks you are suitable for this mission.";
        //quit
    }
    else
    {
        cout << "I do not understand.";
    }
    
    
}
