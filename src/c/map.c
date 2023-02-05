//headers
#include "map.h"

Room *getMap(char *gameMapFile)
{
	static Room fillMap[mapMax];

	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	stream = fopen(gameMapFile, "r");
	if (stream == NULL)
	{
		printf("ERROR: couldn't open or find file: MAP!\n");
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

			Room r;
			r.id = atoi(arr[0]);
			strcpy(r.nameRoom, arr[1]);
			strcpy(r.msgRoom, arr[2]);
			r.successor = atoi(arr[3]);
			r.predecessor = atoi(arr[4]);
			memcpy(r.items, arr[5], sizeof arr[5]);
			r.shopAvailable = atoi(arr[6]);

			fillMap[lineCounter] = r;
			lineCounter += 1;
		}
	}

	free(line);		/* Deallocate allocated memory */
	fclose(stream); /* closing file */

	return fillMap;
};

int getRoomSuccessor(Room *room){
	return room->successor;
}
