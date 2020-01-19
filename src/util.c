#include <stdio.h>
#include <CS101/util.h>

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void array_print(int arr[], int n)
{
	printf("[");
	if (n > 0)
		printf("%d", arr[0]);
	for (int i = 1; i < n; i++)
		printf(", %d", arr[i]);
	printf("]\n");
}
