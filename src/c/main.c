// BIBs
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "map.h"
#include "nav_helper.h"

bool gameRunning;
bool acceptedRules;

//declare needed variables
Room *map;

// content
char *gameInstructionsFile = "../../src/content/game_instructions.txt";
char *gameMapFile = "../../src/content/game.map";

//navigation
int playerPosition = 0;
int lastPlayerPosition = 0;


// function declarations
void printInit();
void acceptInstructions();
void processInput();
int checkExit();


int main()
{
	// define variables
	char userInput[20]; // maximum defined user input length
	gameRunning = 1;

	// init and instructions
	printInit();

	//get Content
	map = getMap(gameMapFile);

	if (acceptedRules == 1)
	{
		while (gameRunning == 1) // while running
		{
			// User Input
			printf("User Input:");
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
	Room r = map[playerPosition];
	if (checkExit(userInput) == 1)
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
	else
	{
		printf("Wrong Input!\n");
	}
}

//function for checking user input of exit
int checkExit(char userInput[20])
{
	if (strcmp(userInput, "esc") == 0 || strcmp(userInput, "exit") == 0 || strcmp(userInput, "quit") == 0)
	{
		return 1;
	}

	return 0;
}

