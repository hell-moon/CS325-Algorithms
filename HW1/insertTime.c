/**
 * CS 325 Algorithms
 * Summer 2019 
 * Xiao Kuang
 * HW1: Insertion Sort Algorithm
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h> // for sleep()

void error(const char *msg)
{
	perror(msg);
	exit(0);
} // Error function used for reporting issues

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
	if (argc != 2)
	{
		error("USAGE: mergeSortAnalysis 'size of list to sort'");
	}
	srand(time(NULL));
	int loopCounter = 5;

	while (loopCounter != 0)
	{
		//use second argument passed in as the size of list to generate
		int sizeList = atoi(argv[1]);
		double time_spent = 0.0;
		int idx = 0;
		// open data.txt for reading, and create new file merge.txt if none exists, and open for truncating and writing
		// FILE *data = fopen("data.txt", "r");
		// FILE *outFile = fopen("merge.txt", "w");
		int buffer[sizeList];

		//fill list with random integers from 0 to 10,000
		for (idx = 0; idx < sizeList; idx++)
		{
			buffer[idx] = rand() % 10001;
		}

		//get time before and after the sort, the difference is the running time
		clock_t begin = clock();
		insertionSort(buffer, sizeList);
		clock_t end = clock();
		time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

		printf("Elapsed time: \t%f \n", time_spent);
		loopCounter--;
	}

	return 0;
}
