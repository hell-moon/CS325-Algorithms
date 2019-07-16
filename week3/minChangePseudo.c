// Assuming array values start at index 1, and index 0 are null, or 0's.
// Assuming value array is sorted from smallest to largest.

minChange(int value[], int valueSize, int A)
{
	// bottom-up approach
	// initialize a 2D array
	int T[valueSize][A] = {-1};
	// loop through the value array starting from i=0; i < valueSize, where valueSize increases each iteration and represents the subset of coin denominations we are mininimizing.
	for( i = 0; i < valueSize; i++{
		// for each subset of values (incrementing each time), minimize the amount of coins to make change for j
		for( j = 0; j < A; j++{
			// if the value corresponding to i is equal to j, then that 1 coin will be the minimum
			if (value[i] == j)
			{
				T[i][j] = 1;
			}
			// else, if the value is larger than j, then is unable to make change at all, so use the minimum coin value for a value[] list omitting the value[i] item.
			else if (value[i] > j)
			{
				T[i][j] = T[i - 1][j];
			}
			// the value is less than j, that means we will choose the smaller values from two options: 
			// 1) the minimum coins for j, using value[] from 1 to i-1 (not choosing to include value[i])
			// 2) the minimum coins for the leftover change from including value[i, + 1
			else
			{
				T[i][j]  = min(T[i-1][j], (1+ T[i][j - value[i]]));
			}
		}
	}
	// initialize an array, C[i], that lists the number of coins that fullfills the global minimal solution
	int C[valueSize] = {0};
	// call a function that computes the values for C[], from the DP table
	countCoins(C, T);
}
