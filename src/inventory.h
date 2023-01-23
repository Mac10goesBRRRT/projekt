#ifndef INVENTORY_H
#define INVENTORY_H

#include "helper.h"

struct item
{
    int id;
    char itemName[20];
};

struct item * getItems()
{
    static struct item getItems[maxItems];

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

			getItems[lineCounter] = i;
			lineCounter += 1;
		}
	}
    return getItems;
}

void showInventory(struct item inventory[100], int inventoryItemCounter)
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


#endif // INVENTORY_H
