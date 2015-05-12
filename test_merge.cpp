#include "merge.cpp"
#include "test.h"
#include <iostream>

int main()
{
	int tidx = 1;
	int X2[2] = {1, 0};
	int Y2[2] = {256, 256};
	int Z2[2] = {0, 1};

	merge(&X2[0], &Y2[0], 0, 1, 2);
	test(tidx++, "merge two elements, wrong order", compare(&X2[0], &Z2[0], 2));
	print_array(X2, 2);

	merge_sort(&X2[0], &Y2[0], 0, 1);
	test(tidx++, "merge_sort two elements, wrong order", compare(&X2[0], &Z2[0], 2));
	print_array(X2, 2);

	X2[0] = 0;
	X2[1] = 1;
	Z2[0] = 0;
	Z2[1] = 1;

	merge(&X2[0], &Y2[0], 0, 1, 2);
	test(tidx++, "merge two elements, right order", compare(&X2[0], &Z2[0], 2));
	print_array(X2, 2);

	int X3[3] = {1, 2, 0};
	int Y3[3] = {256, 256, 256};
	int Z3[3] = {0, 1, 2};

	merge(&X3[0], &Y3[0], 0, 2, 3);
	test(tidx++, "merge 2:1, right order", compare(&X3[0], &Z3[0], 3));
	print_array(X3, 3);

	X3[0] = 2;
	X3[1] = 0;
	X3[2] = 1;
	merge(&X3[0], &Y3[0], 0, 1, 3);
	test(tidx++, "merge 1:2, right order", compare(&X3[0], &Z3[0], 3));
	print_array(X3, 3);

	int X11[11] = {2, 5, 3, 1, 0, 4, 7, 6, 8, 15, 11};
	int Y11[11];
	int Z11[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 11, 15};

	merge_sort(&X11[0], &Y11[0], 0, 11);
	test(tidx++, "merge_sort 11 elements", compare(&X11[0], &Z11[0], 11));
	print_array(X11, 11);

	int X5[5] = {2, 5, 3, 1, 0};
	int Y5[5];
	int Z5[5] = {0, 1, 2, 3, 5};

	merge_sort(&X5[0], &Y5[0], 0, 5);
	test(tidx++, "merge_sort 5 elements", compare(&X5[0], &Z5[0], 5));
	print_array(X5, 5);

	X3[0] = 2; X3[1] = 5; X3[2] = 3;
	Z3[0] = 2; Z3[1] = 3; Z3[2] = 5;
	merge_sort(&X3[0], &Y3[0], 0, 3);
	test(tidx++, "merge_sort 3 elements", compare(&X3[0], &Z3[0], 3));
	print_array(X3, 3);

	int T[1024];
	int B1024[1024];
	for (int i=0; i<1; i++)
	{
	copy(&T[0], &Q1024[0], 1024);
	merge_sort(&T[0], &B1024[0], 0, 1024);
	test(tidx++, "merge sort 1024 elements", compare(&T[0], &A1024[0], 1024));
	}

	return 0;
}


#if 0
(gdb) define fn
>p array[p]@(r-p)
>p *left@n1
>p *right@n2
>end
#endif
