#include "helper.h" //some def's and helpful functions

#include "map.h"
#include "inventory.h"
#include "shop.h"
#include "commands.h"

bool gameRunning;

//content
struct room* map;
struct item inventory[100];
struct item* availableItems;
int inventoryItemCounter = 0;
int commandCounter = 0;

//navigation
int playerPosition = 0;
int lastPlayerPosition = 0;

//INIT
void acceptInstructions()
{
	char userInput[1];
	bool accept = 0;
	int acceptCounter = 0;
	while (accept == 0)
	{
		scanf(" %c", userInput);
		if (strcasecmp(userInput, "y") == 0)
		{
			accept = 1;
		}
		else if (strcasecmp(userInput, "n") == 0)
		{
			accept = 1;
			printf("You didn't accept our rules. The game will close now. \n\n");
			gameRunning = 0;
		}
		else
		{
			printf("Invalid Input!\n");
		}
	}
}

void printInit()
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	stream = fopen("/root/game/src/game_instructions.txt", "r");
	if (stream == NULL)
	{
		printf("ERROR: couldn't open or find file!\n");
		exit(EXIT_FAILURE); // exit
	}

	/* print line by line from file */
	while ((read = getline(&line, &len, stream)) != -1)
	{
		// printf("Retrieved line of length %u :\n", read);
		printf("%s", line);
	}

	free(line);		/* Deallocate allocated memory */
	fclose(stream); /* closing file */

	acceptInstructions();
};



int printStatus()
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

void processInput(char userInput[20])
{
	struct room r = map[playerPosition];
	commandCounter += 1;
	if (strcmp(userInput, "esc") == 0 || strcmp(userInput, "exit") == 0 || strcmp(userInput, "quit") == 0)
	{
		gameRunning = 0;
		printf("!GAME EXIT!\n");
	}
	else if (strcmp(userInput, "north") == 0)
	{
		printf("->N\n");
		lastPlayerPosition = playerPosition;
		if (playerPosition == (int)(mapMax - 1))
		{
			printf("You have reached the border. You have to go in the other direction!\n");
		}
		else
		{
			playerPosition = r.successor;
		}
	}
	else if (strcmp(userInput, "south") == 0)
	{
		printf("->S\n");
		lastPlayerPosition = playerPosition;
		if (playerPosition > 0)
		{
			playerPosition = r.predecessor;
		}
		else
		{
			printf("You have reached the border. You have to go in the other direction!\n");
		}
	}
	else if (strcmp(userInput, "shop") == 0)
	{
		// return 0 if exit or quit - so no item is bought -> return other integers > 0 if item is bought
		int boughtItemID = openShop(availableItems);
		if (boughtItemID > 0)
		{
			inventory[inventoryItemCounter] = availableItems[boughtItemID-1];
			inventoryItemCounter += 1;
		}
	}
	else if (strcmp(userInput, "inventory") == 0)
	{
		showInventory(inventory, inventoryItemCounter);
	}
	else
	{
		printf("Wrong Input!\n");
	}
};

int main()
{
	char userInput[20];
	gameRunning = 1;

	printInit();
	map = getMap();
	availableItems = getItems();

	while (gameRunning == 1)
	{
		// Print current status
		printStatus();

		// User Input
		scanf(" %s", userInput);
		printf("\n");

		// Processing
		processInput(userInput);
	}

	return 0;
};
