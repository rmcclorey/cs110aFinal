/*
 * Group Members: 
 */

// DO NOT CHANGE OR REMOVE THE FOLLOWING LINES
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

#include "interactionFunctions.cpp"
#include "mapFunctions.cpp"
#include "playerFunctions.cpp"
#include "screenFunctions.cpp"
// DO NOT CHANGE OR REMOVE THE PRECEDING LINES

/*
 * FUNCTION PROTOTYPES
 */
// none here yet

int main()
{
	srand(1234);

	doLoadGame('0', true);

	while (true)
	{
		clearScreen();
		printScreen();
		lastMessage = "";

		char input = readCharacterInput();
		if (input == KEYBOARD_QUIT)
		{
			break;
		}
		else if (playerIsAlive())
		{
			doCommand(input);
			doWerewolfNextMove(playerX, playerY);
			doCheckForPlayerDamage();
		}
		else if (input == KEYBOARD_LOAD_GAME)
		{
			doCommand(input);
		}
		else
		{
			lastMessage = "You have died.";
		}
	}

	return 0;
}