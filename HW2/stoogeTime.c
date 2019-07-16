/**
 * CS 325 Algorithms
 * Summer 2019 
 * Xiao Kuang
 * HW1: Stooge Sort Algorithm
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <unistd.h> // for sleep()

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
	// if (argc != 2)
	// {
	// 	error("USAGE: stoogeTime 'size of list to sort'");
	// }
	srand(time(NULL));

	int loopCounter = -5;
	int sizelists[] = {3000, 3200, 3500, 3700, 4000, 4250, 4500, 5000};

	for (loopCounter = 0; loopCounter < 8; loopCounter++)
	{
		//use second argument passed in as the size of list to generate
		int sizeList = sizelists[loopCounter];
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
		stoogeSort(buffer, 0, sizeList - 1);
		clock_t end = clock();
		time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

		/*
		Uncomment the for loop below to print the sorted lists (verify that they are indeed sorted)
	*/
		// for (idx = 0; idx < sizeList; idx++)
		// {
		// 	printf("%d ", buffer[idx]);
		// }
		// printf("\n\n");

		printf("Size: %d Elapsed time: \t%f \n", sizelists[loopCounter], time_spent);
	}

	return 0;
}
