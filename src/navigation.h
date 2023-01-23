#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "helper.h" //some def's and helpful functions
#include "map.h"
#include "commands.h"
#include "inventory.h"

int commandCounter = 0;


int printStatus(struct room map[mapMax], int playerPosition, int lastPlayerPosition)
{

	struct room actualRoom = map[playerPosition];
	char moveMessage[30];

	if (lastPlayerPosition > playerPosition)
	{
		strcpy(moveMessage, "You went to the south!");
	}
	else if (lastPlayerPosition < playerPosition)
	{
		strcpy(moveMessage, "You went to the north!");
	}
	else if (lastPlayerPosition == playerPosition && playerPosition == 0)
	{
		strcpy(moveMessage, "START");
	}
	else
	{
		strcpy(moveMessage, "You didn't move");
	}

	if (lastPlayerPosition != playerPosition || playerPosition == 0 && commandCounter == 0)
	{
		printf("\n\n################################################################################\n");

		printf("--> %s <-- %d\n", moveMessage, playerPosition);
		printf("%s\n", actualRoom.nameRoom);
		printf("%s\n", actualRoom.msgRoom);
		printf("\n");

		getPossibleCommands(map, playerPosition);
	}
}



#endif // NAVIGATION_H
