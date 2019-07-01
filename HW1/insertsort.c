/**
 * CS 325 Algorithms
 * Summer 2019 
 * Xiao Kuang
 * HW1: Insertion Sort Algorithm
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * Notes:  This insertSort was adapted from Java into C, from the khanAcademy challenge: Implement insertion sort, and referenced from geeksForGeeks implementation. 
 */

void insert(int array[], int rightIndex, int value)
{
	int j;
	for (j = rightIndex; j >= 0 && array[j] > value; j--)
	{
		array[j + 1] = array[j];
	}
	array[j + 1] = value;
};

void insertionSort(int array[], int length)
{
	int i;
	for (i = 1; i < length; i++)
	{
		insert(array, i - 1, array[i]);
	}
};

int main(int argc, char *argv[])
{

	int idx = 0;
	// open data.txt for reading, and create new file merge.txt if none exists, and open for truncating and writing
	FILE *data = fopen("data.txt", "r");
	FILE *outFile = fopen("insert.txt", "w");
	int buffer[1000];
	char *lineptr = NULL;
	size_t n = 0;
	int charRead = -5;

	// for each line read in as a string, parse and store in buffer as integers, then call sort on the buffer
	while (charRead = getline(&lineptr, &n, data) > 1)
	{
		// strcpy(buffer, lineptr);
		//printf("%s", buffer);
		char *token;
		token = strtok(lineptr, " ");

		//printf("%s\n", token);
		int arrSize = atoi(token);
		//printf("%d", arrSize);

		token = strtok(NULL, " ");
		for (idx = 0; idx < arrSize; idx++)
		{
			buffer[idx] = atoi(token);
			token = strtok(NULL, " ");
			// printf("%d ", buffer[idx]);
		}
		// printf("\n");

		// here, the list of numbers is read from file and stored in buffer array
		insertionSort(buffer, arrSize);

		// buffer is now sorted, print sorted list to file
		for (idx = 0; idx < arrSize; idx++)
		{
			fprintf(outFile, "%d ", buffer[idx]);
		}
		fprintf(outFile, "\n");
	}
	free(lineptr);

	fclose(data);
	fclose(outFile);
	return 0;

	return 0;
}
