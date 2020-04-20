#include <stdio.h>
#include <CS101/util.h>

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void array_print(int *first, int *last)
{
	printf("[");
	if (first < last)
		printf("%d", *first++);
	while (first < last)
		printf(", %d", *first++);
	printf("]\n");
}
