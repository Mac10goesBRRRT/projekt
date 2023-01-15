#include "/root/game/src/navigation.h"
#include "/root/game/src/helper.h"
#include "/root/game/src/shop.h"

#define MAX_LINE_LENGTH 80 // for instructions
#define mapMax 4		   // for instructions
#define roomAttributesMax 7

struct item itemList[itemsMax];
struct item inventory[100];
int inventoryItemCounter = 0;

bool gameRunning;
struct room map[mapMax];
int playerPosition = 0;
int lastPlayerPosition = 0;
int commandCounter = 0;

void showInventory()
{

	if (inventoryItemCounter == 0)
	{
		printf("*** Inventory is empty *** \n\n");
	}
	else
	{
		printf("*** Inventory *** \n\n");

		for (int i = 0; i < inventoryItemCounter; i++)
		{
			//printf("%d: %d - %s\n", i, inventory[i].id, inventory[i].itemName);
			printf("> %s\n", inventory[i].itemName);
		}
	}

	printf("\n\n");
}

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
		int boughtItemID = openShop(itemList);
		if (boughtItemID > 0)
		{
			inventory[inventoryItemCounter] = itemList[boughtItemID-1];
			inventoryItemCounter += 1;
		}
	}
	else if (strcmp(userInput, "inventory") == 0)
	{
		showInventory();
	}
	else
	{
		printf("Wrong Input!\n");
	}
};

int getMap()
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	stream = fopen("/root/game/src/game.map", "r");
	if (stream == NULL)
	{
		printf("ERROR: couldn't open or find file!\n");
		exit(EXIT_FAILURE); // exit
	}

	char delimiter[] = ";";

	/* print line by line from file */
	int lineCounter = 0;
	while ((read = getline(&line, &len, stream)) != -1)
	{

		// printf("Retrieved line of length %u :\n", read);
		if (startsWith(line, "#") == 0)
		{
			char *arr[roomAttributesMax];
			char *token = strtok(line, delimiter);
			int countToken = 0;
			while (token != NULL)
			{
				arr[countToken] = token;
				token = strtok(NULL, ";");

				countToken += 1;
			}
			free(token);

			struct room r;
			r.id = atoi(arr[0]);
			strcpy(r.nameRoom, arr[1]);
			strcpy(r.msgRoom, arr[2]);
			r.successor = atoi(arr[3]);
			r.predecessor = atoi(arr[4]);
			memcpy(r.items, arr[5], sizeof arr[5]);
			r.shopAvailable = atoi(arr[6]);

			map[lineCounter] = r;
			lineCounter += 1;
		}
	}

	free(line);		/* Deallocate allocated memory */
	fclose(stream); /* closing file */

	return 0;
};

int getItems()
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	stream = fopen("/root/game/src/items.map", "r");
	if (stream == NULL)
	{
		printf("ERROR: couldn't open or find file!\n");
		exit(EXIT_FAILURE); // exit
	}

	char delimiter[] = ";";

	/* print line by line from file */
	int lineCounter = 0;
	while ((read = getline(&line, &len, stream)) != -1)
	{

		// printf("Retrieved line of length %u :\n", read);
		if (startsWith(line, "#") == 0)
		{
			char *arr[itemAttributesMax];
			char *token = strtok(line, delimiter);
			int countToken = 0;
			while (token != NULL)
			{
				arr[countToken] = token;
				token = strtok(NULL, ";");

				countToken += 1;
			}
			free(token);

			struct item i;
			i.id = atoi(arr[0]);
			strcpy(i.itemName, arr[1]);

			itemList[lineCounter] = i;
			lineCounter += 1;
		}
	}
}

void getPossibleCommands()
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

		printf("--> %s <--\n", moveMessage);
		printf("%s\n", actualRoom.nameRoom);
		printf("%s\n", actualRoom.msgRoom);
		printf("\n");

		getPossibleCommands();
	}
}

int main()
{
	char userInput[20];
	gameRunning = 1;

	printInit();
	getMap();
	getItems();

	while (gameRunning == 1)
	{
		// Print current status
		printStatus(playerPosition);

		// User Input
		scanf(" %s", userInput);
		printf("\n");

		// Processing
		processInput(userInput);
	}

	return 0;
};
