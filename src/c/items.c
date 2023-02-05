#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "nav_helper.h"
#include "items.h"

Item *getItems(char *itemsMapFile)
{
	static Item getItems[maxItems];

	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	stream = fopen(itemsMapFile, "r");
	if (stream == NULL)
	{
		printf("ERROR: couldn't open or find file: ITEMS!\n");
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

			Item i;
			i.id = atoi(arr[0]);
			strcpy(i.itemName, arr[1]);
			//printf(arr[2]);
			i.price = atoi(arr[3]);

			getItems[lineCounter] = i;
			lineCounter += 1;
		}
	}
	return getItems;
}
