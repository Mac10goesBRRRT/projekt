// BIBs
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool gameRunning;
bool acceptedRules;

// content
char *gameInstructionsFile = "../../src/content/game_instructions.txt";

// function declarations
void printInit();
void acceptInstructions();

int main()
{
	// define variables
	char userInput[20]; // maximum defined user input length
	gameRunning = 1;

	// init and instructions
	printInit();

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
			// processInput(userInput);
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

//accept rules and instructions for init dialogue
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
			inputState = 1; //break while
		}
		else if (strcasecmp(userInput, "n") == 0)
		{
			printf("You didn't read our rules & instructions. The game will close now. \n\n");
			acceptedRules = 0;
			inputState = 1; //break while
		}
		else
		{
			printf("Invalid Input!\n");
		}
	}
}