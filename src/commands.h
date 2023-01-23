#ifndef COMMANDS_H
#define COMMANDS_H

#include "helper.h"
#include "map.h"

void getPossibleCommands(struct room map[mapMax], int playerPosition)
{
	struct room r = map[playerPosition];
	char commands[][20] = {};

	if (playerPosition > 0)
	{
		printf("You can move south from here\n");
	}

	if (playerPosition < mapMax - 1)
	{
		printf("You can move north from here\n");
	}

	if (r.shopAvailable == 1)
	{
		printf("You can call 'shop' to buy items.");
	}

	printf("\n");
}


#endif // COMMANDS_H