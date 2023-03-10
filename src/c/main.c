// BIBs
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "map.h"
#include "nav_helper.h"
#include "items.h"
#include "shop.h"
#include "player.h"
#include "commands.h"

bool gameRunning;
bool acceptedRules;

// declare needed variables
Room *map;
Item *availableItems;
Player actualPlayer;
int inputCounter = 0;

// content
char *gameInstructionsFile = "../../src/content/game_instructions.txt";
char *gameMapFile = "../../src/content/game.map";
char *itemsMapFile = "../../src/content/items.map";

// navigation
int playerPosition = 0;
int lastPlayerPosition = 0;

// function declarations
void printInit();
void setUp();
void acceptInstructions();
void processInput();
int checkExit();
int checkMove();
void printStatus();

int main()
{
	// init and instructions
	printInit();

	if (acceptedRules == 1)
	{
		setUp();

		char userInput[20];		 // maximum defined user input length
		while (gameRunning == 1) // while running
		{
			// Print current status
			printStatus();

			// User Input
			scanf(" %s", userInput);
			printf("\n");

			// NEXT STEP:
			// Processing
			processInput(userInput);
		}
	}
	return 0;
}

// init dialogue
void printInit()
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	stream = fopen(gameInstructionsFile, "r");
	if (stream == NULL)
	{
		printf("ERROR: couldn't open or find file: INSTRUCTIONS !\n");
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
}

// setUp
void setUp()
{
	// define variables
	actualPlayer.id = 1;
	actualPlayer.wallet = 100;
	gameRunning = 1;

	// get Content
	map = getMap(gameMapFile);
	availableItems = getItems(itemsMapFile);
}

// accept rules and instructions for init dialogue
void acceptInstructions()
{
	char userInput[1];
	bool inputState = 0;
	int acceptCounter = 0;
	while (inputState == 0)
	{
		scanf(" %c", userInput);
		if (strcasecmp(userInput, "y") == 0)
		{
			acceptedRules = 1;
			inputState = 1; // break while
		}
		else if (strcasecmp(userInput, "n") == 0)
		{
			printf("You didn't read our rules & instructions. The game will close now. \n\n");
			acceptedRules = 0;
			inputState = 1; // break while
		}
		else
		{
			printf("Invalid Input!\n");
		}
	}
}

// process user input
void processInput(char userInput[20])
{
	if (checkExit(userInput) == 1)
	{
		gameRunning = 0;
		printf("!GAME EXIT!\n");
	}
	else if (strcmp(userInput, "shop") == 0)
	{
		Room actualRoom = map[playerPosition];
		if (actualRoom.shopAvailable == 1)
		{
			int *result = malloc(sizeof(int) * 2);
			result = openShop(availableItems, actualPlayer); // result > 0 -> integer = index of item OR result = 0 -> cancel
			if (result[0] == 0)
			{
				actualPlayer = buyItem(availableItems, result[1], actualPlayer);
			}
			else if (result[0] == 1)
			{
				actualPlayer = sellItem(result[1], actualPlayer);
			}
		}
		else
		{
			printf("You can't access the shop from here.");
		}
	}
	else if (strcmp(userInput, "inventory") == 0)
	{
		showInventory(actualPlayer);
	}
	else if (checkMove(userInput) == 1)
	{
		printf("Wrong Input!\n");
	}
}

// function for checking user input of exit
int checkExit(char userInput[20])
{
	if (strcmp(userInput, "esc") == 0 || strcmp(userInput, "exit") == 0 || strcmp(userInput, "quit") == 0)
	{
		return 1;
	}

	return 0;
}

// check is user moved
int checkMove(char userInput[20])
{
	Room r = map[playerPosition];
	inputCounter += 1;
	if (strcmp(userInput, "north") == 0)
	{
		lastPlayerPosition = playerPosition;
		if (playerPosition == (int)(mapMax - 1))
		{
			printf("You have reached the border. You have to go in the other direction!\n");
		}
		else
		{
			playerPosition = r.successor;
		}

		return 0;
	}
	else if (strcmp(userInput, "south") == 0)
	{
		lastPlayerPosition = playerPosition;
		if (playerPosition > 0)
		{
			playerPosition = r.predecessor;
		}
		else
		{
			printf("You have reached the border. You have to go in the other direction!\n");
		}

		return 0;
	}
	else
	{
		return 1;
	}
}

// print actual location and messages from game.map
void printStatus()
{
	Room actualRoom = map[playerPosition];
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

	if (lastPlayerPosition != playerPosition || playerPosition == 0 && inputCounter == 0)
	{
		printf("\n\n################################################################################\n");

		printf("--> %s <--\n", moveMessage);
		printf("%s\n", actualRoom.nameRoom);
		printf("%s\n", actualRoom.msgRoom);
		printf("\n");

		char *possibleCommands = malloc(sizeof(char) * (500));
		possibleCommands = getPossibleCommands(map[playerPosition], playerPosition);
		printf("%s", possibleCommands);
		free(possibleCommands);
	}
}