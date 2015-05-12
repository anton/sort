#include "insert.cpp"
#include "test.h"
#include <iostream>

int main()
{
	int tidx = 0;

	int Q[6] = { 5, 2, 4, 6, 1, 3 };
	int A[6] = { 1, 2, 3, 4, 5, 6 };

	insertion_sort(&Q[0], array_count(Q));
	test(tidx++, "insertion sort 6 elements", compare(&Q[0], &A[0], 6));
	print_array(Q, 6);

	int X11[11] = {2, 5, 3, 1, 0, 4, 7, 6, 8, 15, 11};
	int Z11[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 11, 15};

	insertion_sort(&X11[0], array_count(X11));
	test(tidx++, "insertion sort 11 elements", compare(&X11[0], &Z11[0], 11));
	print_array(X11, array_count(X11));

	int T[1024];
	for (int i=0; i<1; i++)
	{
	copy(&T[0], &Q1024[0], 1024);
	insertion_sort(&T[0], 1024);
	test(tidx++, "insertion sort 1024 elements", compare(&T[0], &A1024[0], 1024));
	}

	return 0;
}
