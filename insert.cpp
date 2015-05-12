void insertion_sort(int *A, int len)
{
	for (int j = 1; j < len; j++)
	{
		int key = A[j];
		// Insert A[j] into the sorted sequence A[1..j-1]
		int i = j - 1;
		while ((i >= 0) && (A[i] > key))
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}
