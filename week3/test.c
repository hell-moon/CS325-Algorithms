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

void knapSack(int val[], int weight[], int members[], int N, int W, int M)
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
  // printf("Total Price %d\n", T[N][W]);
  // for each member, list items they carry

  int total = 0;
  for (i = 0; i < M; i++)
  {
    int n = N;
    printf("%d: ", i + 1);
    j = members[i];
    total += T[N][j];
    while (j > 0 && n > 0)
    {
      if (T[n][j] == T[n - 1][j])
      {
        n--;
      }
      else
      {
        printf("%d ", n);
        n--;
        j = j - weight[n];
      }
    }
    printf("\n");
  }
  printf("Total Price %d\n\n", total);

  // printf("\n");
  // for (i = 0; i < N + 1; i++)
  // {
  //   for (j = 0; j < W + 1; j++)
  //   {
  //     printf("%d ", T[i][j]);
  //     if (j == W)
  //     {
  //       printf("\n");
  //     }
  //   }
  // }
}

int maxMembers(int members[], int M)
{
  int max = -1;
  int i = 0;
  for (i = 0; i < M; i++)
  {
    if (members[i] > max)
    {
      max = members[i];
    }
  }
  return max;
}

int main()
{
  int N = 6;
  int M = 4;

  int val[] = {32, 43, 26, 50, 20, 27};
  int weight[] = {16, 12, 4, 8, 3, 9};
  int members[] = {25, 23, 21, 19};
  int W = maxMembers(members, M);

  knapSack(val, weight, members, N, W, M);
}
