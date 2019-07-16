#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

// void printTable(int T[][], int N, int W)
// {
// 	int i, j;
// 	for (i = 0; i < N + 1; i++)
// 	{
// 		for (j = 0; j < W + 1; j++)
// 		{
// 			printf("%d ", T[i][j]);
// 			if (j == W)
// 			{
// 				printf("\n");
// 			}
// 		}
// 	}
// }

void knapSack(int val[], int weight[], int N, int W)
{
	// make DP table, 6 rows x 25
	int T[N + 1][W + 1];
	// fill first row and column with 0
	int i, j, k;
	for (i = 0; i < N + 1; i++)
	{
		T[i][0] = 0;
	}
	for (j = 0; j < W + 1; j++)
	{
		T[0][j] = 0;
	}

	// build DP table
	for (i = 1; i < N + 1; i++)
	{
		for (j = 1; j < W + 1; j++)
		{
			if (weight[i - 1] <= j)
			{
				T[i][j] = max(val[i - 1] + T[i - 1][j - weight[i - 1]], T[i - 1][j]);
			}
			else
			{
				T[i][j] = T[i - 1][j];
			}
		}
	}
	printf("\n");
	for (i = 0; i < N + 1; i++)
	{
		for (j = 0; j < W + 1; j++)
		{
			printf("%d\t", T[i][j]);
			if (j == W)
			{
				printf("\n");
			}
		}
	}
}

int main()
{
	int N = 6;
	int W = 25;

	int val[] = {32, 43, 26, 50, 20, 27};
	int weight[] = {16, 12, 4, 8, 3, 9};
	knapSack(val, weight, N, W);
}
