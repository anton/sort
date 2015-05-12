#include "merge.cpp"
#include "insert.cpp"

void timsort(int *array, int *buffer, int p, int r)
{
	if (r - p < 2)
	{
		return;
	}

	int q = (p + r) / 2;

	if (q - p > 64)
	{
		timsort(array, buffer, p, q);
	}
	else
	{
		insertion_sort(&array[p], (q - p));
	}

	if (r - q > 64)
	{
		timsort(array, buffer, q, r);
	}
	else
	{
		insertion_sort(&array[q], (r - q));
	}

	merge(array, buffer, p, q, r);
}
