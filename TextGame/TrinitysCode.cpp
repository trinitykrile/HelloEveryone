// TrinitysCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <string>

using namespace std;


int main()
{
	string choice = "";
	string name = "";
	string riddle = "";
	string window = "unlocked";
	string key = "no";
	string location = "start";


	cout << "What is your name?\n>";
	cin >> name;
	cout << name << ", the Great Sorceror has recruited you for a special mission. You must find a magical paper clip and bring it to him.\nIf you are successful, he will reward you with a lifetime of riches.\n";


	while (choice != "quit")
	{
		if (location == "start")
		{
			cout << "You are at the start in a room with three doors, one to the north, one to the west, and one to the east.\n";
			cout << "You can go through a door ('north', 'east', 'west') or 'explore' the current room.\n>";
			cin >> choice;

			if (choice == "explore")
			{
				cout << "There is an oven, a desk, and a table. You can explore the 'oven', 'desk', or 'table', or go 'back'.\n>";
				cin >> choice;
				if (choice == "back")
				{
					string location = "start";
				}
				else if (choice == "desk")
				{
					cout << "Looks like there are some pencils and a stack of lined paper.\n";
				}
				else if (choice == "oven")
				{
					cout << "Looking for a paper clip in an oven, " << name << "? Unfortunatly, the Soceror no longer thinks you are suitable for this mission.\nYou lose.\n";
					choice = "quit";
				}
				else if (choice == "table")
				{
					cout << "There is nothing on the table.\n";
				}
				else if (choice != "quit")
				{
					cout << "I do not understand.\n";
				}
			}
			else if (choice == "north")
			{
				location = "NorthDoor";
			}
			else if (choice == "west")
			{
				location = "WestRoom";
			}
			else if (choice == "east")
			{
				location = "EastRoom";
			}
			else if (choice == "south")
			{
				location = "SouthRoom";
			}
			else if (choice != "quit")
			{
				cout << "I do not understand.\n";
			}
		}

		else if (location == "NorthDoor") //Added the NorthDoor which requires a key to unlock.
		{
			if (key == "no")
			{
				cout << "The door is locked.\n";
				location = "start";
			}
			else if (key == "yes")
			{
				cout << "You used the key to unlock the door.\n";
				location = "NorthRoom";
			}
		}

		else if (location == "NorthRoom" && key == "yes") //Added the NorthRoom which is accessed by a key.
		{
			cout << location << ".\nYou are in a room with a cabinet and what looks like some writing on the wall. You can explore the 'cabinet', the 'writing', or 'exit' the room.\n>";
			cin >> choice;
			if (choice == "writing") //Added a riddle (used to open the box)
			{
				cout << "A message scratched into the wall reads 'When I take five and add six, I get eleven, but when I take six and add seven, I get one.'\n";
				location = "NorthRoom";
			}
			else if (choice == "cabinet") //Added a monster
			{
				cout << "You opened the cabinet.\nOh no! A goblin jumped out and cornered you!\nYou can 'run' or 'fight'\n>";
				cin >> choice;
				if (choice == "run")
				{
					cout << "You got away!\n";
					location = "start";
				}
				else if (choice == "fight")
				{
					cout << "You were not strong enough to defeat the goblin!\n";
					choice = "quit";
				}
			}
			else if (choice == "exit")
			{
				location = "start";
			}
			else if (choice != "quit")
			{
				cout << "I do not understand.\n";
			}
		}

		else if (location == "WestRoom")
		{
			cout << location << ".\nYou are in a room with a window. A box is sitting on the floor. You can open the 'box', go to the 'window', or 'exit' WestRoom.\n>";
			cin >> choice;
			if (choice == "box")
			{
				cout << "There is a keyboard on the box. Would you like to try to input a word? 'yes' or 'no'.\n>";
				cin >> choice;
				if (choice == "yes")
				{
					cout << "Type here.\n>";
					cin >> riddle;
					if (riddle == "clock")
					{
						cout << "The box opened! You have found the paper clip!\n";
						if (window == "locked")
						{
							cout << "You win! You have been gifted infinite riches by the Great Soceror. He can now keep the rough draft of his novel together.\n";
							choice = "quit";
						}
						else
						{
							cout << "Oh no! A gremlin got in through the window and took the paper clip before you could grab it!\nYou lose.\n";
							choice = "quit";
						}
					}
					else
					{
						cout << "The box didn't open.\n";
						location = "WestRoom";
					}
				}
			}
			else if (choice == "window")
			{
				cout << "The window is " << window << ". You can 'lock' it, or go 'back'.\n>";
				cin >> choice;
				if (choice == "lock")
				{
					window = "locked";
					cout << "You locked the window.\n";
				}
				else if (choice == "back")
				{
					location = "WestRoom";
				}
				else if (choice != "quit")
				{
					cout << "I do not understand.\n";
				}
			}
			else if (choice == "exit")
			{
				location = "start";
			}
			else if (choice != "quit")
			{
				cout << "I do not understand.\n";
			}

		}

		if (location == "EastRoom")
		{
			cout << location << ". \nThere are no windows in this room, but there is a desk by the far wall. You can look in the 'desk' or 'exit' the room.\n>";
			cin >> choice;
			if (choice == "desk")
			{
				cout << "There is a key in the desk. You picked it up.\n";
				key = "yes";
			}
			else if (choice == "exit")
			{
				location = "start";
			}
			else if (choice != "quit")
			{
				cout << "I do not understand.";
			}
		}
		else if (location == "SouthRoom")
		{
			cout << name << ", you ran into a wall. Unfortunatly, the socerer no longer thinks you are suitable for this mission.\nYou lose.\n";
			choice = "quit";
		}

		if (choice == "i" || choice == "inventory")
		{
			if (key == "yes")
			{
				cout << "You have the key.\n";
			}

			else if (key != "yes") // add more later, for example if you had a crowbar, it would be else if (key != yes && crowbar != yes) and so on if you had extra items.
			{
				cout << "You do not have any items.\n";
			}

			cout << "You are in the " << location << ".\n"; // You can change the names of the locations to have them make more sense if needbe.
			cout << "Press (h) at any time to get information about commands.";
		}

		if (choice == "h" || choice == "help")
		{
			cout << ""; // add whatever a player might need help with in the future.
		}
	}
	return 0;
}
