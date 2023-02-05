//BIBs
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool gameRunning;

int main()
{
	//define variables
	char userInput[20]; //maximum defined user input length
	gameRunning = 1; 

	while (gameRunning == 1) //while running
	{
		// User Input
		printf("User Input:");
		scanf(" %s", userInput);
		printf("\n");

		//NEXT STEP:
		//Processing
		//processInput(userInput);
	}

	return 0;
};