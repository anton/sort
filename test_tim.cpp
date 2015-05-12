#if TIMSORT
#include "tim.cpp"
#else
#include "merge.cpp"
#endif

#include "test.h"
#include <iostream>

int main()
{
	int tidx = 1;

	int B256[256];

#if TIMSORT
	timsort(&Q256[0], &B256[0], 0, 256);
	test(tidx++, "timsort 256 elements", compare(&Q256[0], &A256[0], 256));
#else
	merge_sort(&Q256[0], &B256[0], 0, 256);
	test(tidx++, "merge sort 256 elements", compare(&Q256[0], &A256[0], 256));
#endif

	int B4096[4096];
#if TIMSORT
	timsort(&Q4096[0], &B4096[0], 0, 4096);
	test(tidx++, "timsort 4096 elements", compare(&Q4096[0], &A4096[0], 4096));
#else
	merge_sort(&Q4096[0], &B4096[0], 0, 4096);
	test(tidx++, "merge sort 4096 elements", compare(&Q4096[0], &A4096[0], 4096));
#endif

	return 0;
}
