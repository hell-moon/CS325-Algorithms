#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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
	if (upper - lower +1 > 2)
	{
		int third = ceil(upper - lower + 1)/3;
		// int upperTwoThirds = ceil(upper - ((0.67) * (upper - lower)));

		// 	call stoogeSort() on lower 2/3 of list
		stoogeSort(list, lower, upper - third);
		//  call stoogeSort() on upper 2/3 of list
		stoogeSort(list, lower + third, upper);
		//  call stoogeSort() on lower 2/3 of list again
		stoogeSort(list, lower, upper - third);
	}
}

int main()
{
	int list[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	stoogeSort(list, 0, 9);
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
	return 0;
}
