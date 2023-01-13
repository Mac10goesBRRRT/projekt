#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "navigation.h"

bool gameRunning;
#define MAX_LINE_LENGTH 80


int main()
{
	printInit();

	char userInput[20];
	gameRunning = 1;

	while (gameRunning == 1)
	{
		// Print current status
		// printStatus(player, mapPosition);

		// Get and parse user input
		// string userInput;
		// Input Function
		scanf("%s", userInput);

		// Processing
	}

	return 0;
}


void printInit()
{
	printf("GAME LAUNCHED\n");
	printf("*******************\n\n");
	
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	stream = fopen("/root/game/src/game_instructions.txt", "r");
	if (stream == NULL)
	{
		printf("ERROR\n");
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, stream)) != -1)
	{
		//printf("Retrieved line of length %u :\n", read);
		printf("%s", line);
	}

	free(line);
	fclose(stream);
	
}



