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
// TODO: sort start time from largest to smallest inside struct
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

struct activities
{
	int start;
	int finish;
};

int main()
{

	int s[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
	int f[] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};

	struct activities list[20];

	int n = 11;
	int i, j, k;
	for(i = 0; i < 11; i++){
		list[i].start = s[i];
		list[i].finish = f[i];
	}



	return 0;
}
