#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "map.h"

char* getPossibleCommands(Room r, int playerPosition)
{
	char commands[][20] = {};
	
	char *msg = malloc(sizeof(char) * (500));
	strcpy(msg, ""); //assign char (string) that no leading zero result
	if (playerPosition > 0)
	{
		strcat(msg, "You can move south from here\n");
	}

	if (playerPosition < mapMax - 1)
	{
		strcat(msg, "You can move north from here\n");
	}

	if (r.shopAvailable == 1)
	{
		strcat(msg, "You can call 'shop' to buy items.\n");
	}

	return msg;
}
