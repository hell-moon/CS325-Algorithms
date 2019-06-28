/**
 * CS 325 Algorithms
 * Summer 2019 
 * Xiao Kuang
 * HW1: Merge Sort Algorithm
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * Notes:  This mergeSort was adapted from Java into C, from the khanAcademy challenge: Implement merge, and referenced from geeksForGeeks implementation. 
 */

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
	int idx = 0;
	// open data.txt for reading, and create new file merge.txt if none exists, and open for truncating and writing
	FILE *data = fopen("data.txt", "r");
	FILE *outFile = fopen("merge.txt", "w");
	int buffer[1000];
	char *lineptr = NULL;
	size_t n = 0;
	int charRead = -5;

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
		mergeSort(buffer, 0, arrSize - 1);

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
