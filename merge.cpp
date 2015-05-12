#define Assert(Expression)                                                     \
	if (!(Expression))                                                     \
	{                                                                      \
		__builtin_trap();                                              \
	}

void merge(int *array, int *buffer, int begin, int mid, int end)
{
	Assert(begin <= mid);
	Assert(mid < end);

	int n1 = mid - begin;
	int n2 = end - mid;
	int *left = &buffer[0];
	int *right = &buffer[mid];

#if 0
	if (n1 == 2)
	{
		Assert(n2 != 0);
	}

	if (n2 == 2)
	{
		Assert(n1 != 0);
	}
#endif

	for (int i = 0; i < n1; i++)
	{
		left[i] = array[begin + i];
	}

	for (int j = 0; j < n2; j++)
	{
		right[j] = array[mid + j];
	}

	int i = 0;
	int j = 0;
	for (int k = begin; k < end; k++)
	{
		if ((i < n1) && (j >= n2 || left[i] <= right[j]))
		{
			array[k] = left[i++];
		}
		else
		{
			array[k] = right[j++];
		}
	}
}

void merge_sort(int *array, int *buffer, int p, int r)
{
	if (r - p < 2)
	{
		return;
	}

	int q = (p + r) / 2;
	merge_sort(array, buffer, p, q);
	merge_sort(array, buffer, q, r);
	merge(array, buffer, p, q, r);
}

