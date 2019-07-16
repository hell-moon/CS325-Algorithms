
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void error(const char *msg)
{
	perror(msg);
	exit(0);
} // Error function used for reporting issues

// swap the values at the indexes i, j in list
void swap(int list[], int i, int j)
{
	int temp = list[i];
	list[i] = list[j];
	list[j] = temp;
}

void stoogeSort(int list[], int lower, int upper)
{
	// if value of list at lower is greater than at upper, swap the values
	if (list[lower] > list[upper])
	{
		swap(list, lower, upper);
	}
	// if there are 3 or more elements in the array then
	if ((upper - lower + 1) > 2)
	{
		int third = ceil(upper - lower + 1) / 3;
		// int upperTwoThirds = ceil(upper - ((0.67) * (upper - lower)));
		// 	call stoogeSort() on lower 2/3 of list
		stoogeSort(list, lower, upper - third);
		//  call stoogeSort() on upper 2/3 of list
		stoogeSort(list, lower + third, upper);
		//  call stoogeSort() on lower 2/3 of list again
		stoogeSort(list, lower, upper - third);
	}
}

int main(int argc, char *argv[])
{

	int idx = 0;
	// open data.txt for reading, and create new file merge.txt if none exists, and open for truncating and writing
	FILE *data = fopen("data.txt", "r");
	if(data == NULL){
		error("unable to open data.txt");
	}
	FILE *outFile = fopen("stooge.txt", "w");
	if(outFile == NULL){
		error("unable to open stooge.txt");
	}
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
		// get first token separated by a space, from line.  This is the size of the list. 
		token = strtok(lineptr, " ");

		//printf("%s\n", token);
		// convert from string to integer
		int arrSize = atoi(token);
		//printf("%d", arrSize);

		// keep parsing the rest of the line and converting to integer
		token = strtok(NULL, " ");
		for (idx = 0; idx < arrSize; idx++)
		{
			buffer[idx] = atoi(token);
			token = strtok(NULL, " ");
			// printf("%d ", buffer[idx]);
		}
		// printf("\n");

		// here, the list of numbers is read from file and stored in buffer array
		stoogeSort(buffer, 0, arrSize - 1);

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
}
