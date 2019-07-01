/**
 * CS 325 Algorithms
 * Summer 2019 
 * Xiao Kuang
 * HW1: Merge Sort Algorithm
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h> // for sleep()

// #include <random.h>

/**
 * Notes:  This mergeSort was adapted from Java into C, from the khanAcademy challenge: Implement merge, and referenced from geeksForGeeks implementation. 
 */

void error(const char *msg)
{
	perror(msg);
	exit(0);
} // Error function used for reporting issues

void merge(int arr[], int l, int m, int r)
{
	// assume subarrays from arr[l...m] and arr[m+1...r] are sorted
	// merge the two subarrays into one sorted array

	int i, j, k;
	int nL = (m - l) + 1; //size of left subarray
	int nR = (r - m);			//size of right subarray
	// create temporary arrays to store arr[l...m] and arr[m+1...r]
	int L[nL];
	int R[nR];
	for (i = 0; i < nL; i++)
	{
		L[i] = arr[l + i];
	}
	for (i = 0; i < nR; i++)
	{
		R[i] = arr[m + 1 + i];
	}

	// merge the temporary arrays back into arr[1...r]
	int minSize = -1;
	if (nL <= nR)
	{
		minSize = nL;
	}
	else
	{
		minSize = nR;
	}

	k = l; //keep track of merged array
	i = 0; //keep track of left subarray
	j = 0; //keep track of right subarray
	while (i < nL && j < nR)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// copy any remaining elements of left and right subtrees into arr[]
	while (i < nL)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < nR)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (r > l)
	{
		// find middle point to divide array into two halves
		int m = l + (r - l) / 2;
		// call mergeSort for first half
		mergeSort(arr, l, m);
		// call mergeSort for second half
		mergeSort(arr, m + 1, r);
		// merge the two halves sorted from above
		merge(arr, l, m, r);
	}
}

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

		int sizeList = atoi(argv[1]);
		double time_spent = 0.0;
		int idx = 0;
		// open data.txt for reading, and create new file merge.txt if none exists, and open for truncating and writing
		// FILE *data = fopen("data.txt", "r");
		// FILE *outFile = fopen("merge.txt", "w");
		int buffer[sizeList];

		for (idx = 0; idx < sizeList; idx++)
		{
			buffer[idx] = rand() % 10001;
			//printf("%d ", buffer[idx]);
		}

		//get time before and after the sort, the difference is the running time
		clock_t begin = clock();
		mergeSort(buffer, 0, sizeList - 1);
		clock_t end = clock();
		time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
		// for (idx = 0; idx < sizeList; idx++)
		// {
		// 	// buffer[idx] = rand()%10001;
		//
		// }
		printf("Elapsed time: \t%f \n", time_spent);
		loopCounter--;
	}

	return 0;
}
